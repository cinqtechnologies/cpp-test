#include <iostream>

/**
 * @brief Computes fibonacci.
 * @param n The n-th number which we want to compute fibonacci.
 * @return A 64 bit unsigned containing the N number of fibonacci squence.
 *
 * @note We use the iterative approach to avoid stack overflow and slowness.
 */
unsigned long long fibonacci(const int n);

int main(int argc, char** argv)
{
    int n;
    std::cin >> n;

    std::cout << fibonacci(n) << "\n";

    return 0;
}

unsigned long long fibonacci(const int n)
{
    if(n <= 0)
        return 0;
    else if(n == 1)
        return 1;

    unsigned long long f1 = 0;
    unsigned long long f2 = 1;
    unsigned long long ret;

    int x = n;

    while( x > 1)
    {
        ret = f1 + f2;
        f1 = f2;
        f2 = ret;

        --x;
    }

    return ret;
}
