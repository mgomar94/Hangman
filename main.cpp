#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
#include <string>
#include <stdio.h>
#include <stdlib.h> 


int main(int argc, char* argv[]) {

    /* Check to ensure the correct number of inputs is given */
    if(argc != 3) {
        std::cerr << "Usage: " << argv[0] 
                << " desiredWordLength fileName.txt" << std::endl;
        return -1;
    }
    
    int wordLength = argv[1];
    
    
    /* Open the file */
    ifstream in;
    in.open(argv[2]);

    /* Check if input file was actually opened */
    if(!in.is_open()) 
    {
        cout<< "Invalid input file. No file was opened. Please try again.\n";
        return -1;
    }
    
	else {
        
        vector<string> wordList;
        std::string word = "";

        
        while (getline(in, word)) {
            if(word.length() == wordLength){
                wordList.push_back(word);
            }
        }
	}
	
	srand(time(NULL));
	int randomInt = rand() % (wordList.size() - 1);
	
	string wordToGuess = wordList.at(randomInt);
	vector<char> currWord;
	for(int i = 0; i < wordLength - 1; i++){
	    currWord.push_back('_');
	}
	
	
	
	char prompt = '';
	bool gameOver = false;
    while (!gameOver) {
        
        for(auto i = currWord.begin(); i != currWord.end(); i++){
            std::cout << *i;
        }
        
        
    
        cout << "Enter your guess" << endl;
        getline(cin, name);
        
       
       
       
       
        std::cout << "Search again? (y/n)" << std::endl;
        cin >> prompt;  // Get the first character
        // Then ignore until newline
        cin.ignore( numeric_limits <streamsize> ::max(), '\n' );  
    }
    in.close();


    return 0;
}