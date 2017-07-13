#include <iostream>
#include <string>

bool is_palindrome(std::string target)
{
    int li = 0, ri = target.length() - 1;

    while(li < ri)
    {
	if (target[li] != target[ri])
	    return false;
	
	li++; 
	ri--;
    }

    return true;
}

int main(int argc, char** argv)
{
    std::string word;
    
    int nwords = 0;
    std::cin >> nwords;

    // Repeat NWORDS times
    while(nwords--)
    {
	std::cin >> word;

	// Check if it is palidrome
	if( is_palindrome(word) )
	    std::cout << word << " is palindrome" << std::endl;
	else
	    std::cout << word << " is not palindrome" << std::endl;
    }
    
    return 0;
}
