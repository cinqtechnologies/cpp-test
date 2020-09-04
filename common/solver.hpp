#pragma once

#include <iostream>
#include <functional>

namespace cpptest::solver {

    typedef std::function<void(std::istream &, std::ostream &)> Solution;

    namespace internal {
        class BaseSolver {
        public:
            BaseSolver(int argc, char **argv);

            void test(const Solution &solution) const noexcept;

            void execute(const Solution &solution) const noexcept;

        protected:
            const std::string& challenge() const noexcept { return challengeName; }
            virtual void handleSolution(std::istream& in, std::ostream& out, const Solution &solution) const noexcept = 0;

        private:
            std::string challengeName;
        };
    }

    class basic : public internal::BaseSolver {
    public:
        basic(int argc, char** argv);
        void handleSolution(std::istream& in, std::ostream& out, const Solution &solution) const noexcept override;

    };

    class codejam : public internal::BaseSolver {
    public:
        codejam(int argc, char** argv);
        void handleSolution(std::istream& in, std::ostream& out, const Solution &solution) const noexcept override;

    };
}