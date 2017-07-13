#include <iostream>
#include <string>

int main(int argc, char** argv)
{
    std::string word;
    int nlines = 0;
    int ndirty = 0;
    int nfound;
    
    std::cin >> nlines;

    while(nlines--)
    {
	std::cin >> nfound >> word;
	if (word.compare("dirty") == 0)
	    ndirty += nfound;
    }

    if(ndirty > 0)
	std::cout << "There are "
		  << ndirty
		  << " dirty bills." << std::endl;
    else
	std::cout << "There are no dirty bills." << std::endl;
    
    return 0;
}
