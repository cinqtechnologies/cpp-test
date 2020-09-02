#include "solver.hpp"

#include <filesystem>
#include <fstream>

using namespace cpptest::solver;

////////////////
// base_solver
////////////////

internal::BaseSolver::BaseSolver(int argc, char **argv)
    : challengeName(std::filesystem::path(argv[0]).filename())
{
}

void internal::BaseSolver::test(const Solution &solution) const noexcept {
    const auto cwd = std::filesystem::current_path();
    const auto testsDir = cwd.parent_path() / "challenges" / challengeName / "tests";

    using std::filesystem::directory_iterator;
    auto numberOfTests = std::distance(directory_iterator(testsDir), directory_iterator{}) / 2;

    for (int i = 1; i <= numberOfTests; i++) {
        std::string testName = "input" + std::to_string(i) + ".txt";
        std::ifstream in(testsDir / testName);
        handleSolution(in, std::cout, solution);
    }
}

void internal::BaseSolver::execute(const Solution &solution) const noexcept {
    handleSolution(std::cin, std::cout, solution);
}

////////////////
// basic solver
////////////////

basic::basic(int argc, char **argv)
    : BaseSolver(argc, argv)
{
}

void basic::handleSolution(std::istream& in, std::ostream& out, const Solution &solution) const noexcept {
    solution(in, out);
}


////////////////
// code jam solver
////////////////

codejam::codejam(int argc, char **argv)
    : BaseSolver(argc, argv)
{
}

void codejam::handleSolution(std::istream& in, std::ostream& out, const Solution &solution) const noexcept {
    int N;
    in >> N;
    while (N-- > 0) {
        solution(in, out);
    }
}