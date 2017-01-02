#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>

using namespace std;

bool isAnagram(string word1, string word2){

	size_t position;

	if(word1.size() != word2.size()){
		return false;
	}

	for(int i = 0; i < word1.size(); i++){

		position = word2.find(word1[i]);
		if (position == string::npos){
			return false;
		}
	}

	return true;
}

int main(int argc, char** argv)
{

	ifstream txtInput ("tests/input2.txt");
	int nLines;
	std::string strNLines,wordOne, wordTwo;

	if (txtInput.is_open()){

    while (!txtInput.eof()){

			std::getline(txtInput, strNLines);
			nLines = atoi(strNLines.c_str());

			for (int i = 0; i < nLines; i++) {

				std::getline(txtInput, wordOne, ' ');
				std::getline(txtInput, wordTwo);

				if (isAnagram(wordOne, wordTwo)){
					std::cout << wordOne << " is an anagram of " << wordTwo << std::endl;
				}	else {
					std::cout << wordOne << " is not an anagram of " << wordTwo << std::endl;
				}

			}

			txtInput.close();
		}
	}

	return 0;

}
