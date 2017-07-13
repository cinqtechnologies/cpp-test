#include <iostream>

unsigned long fibonacci(int x)
{
    unsigned long output[2] = {0, 1};
    int it = -1;

    if(x < 0)
	return 0;

    while(++it < x)
	output[it % 2] = output[0] + output[1];
    
    return output[it % 2];
}

int main(int argc, char** argv)
{
    int x;
    std::cin >> x;
    std::cout << fibonacci(x) << std::endl;
    return 0;
}
