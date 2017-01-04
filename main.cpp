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
        
        /* Create a vector of strings to store words of desired length */
        vector<string> wordList;
        std::string word = "";

        /** While there are still words to be read in from the input file,
         *  Check if the next word has a length that matches the desired length
         *  inputted by the user. If so, add it to the vector. Else, continue
         *  reading from the input file.
         */
        while (getline(in, word)) {
            if(word.length() == wordLength){
                wordList.push_back(word);
            }
        }
	}
	
	/* Randomly select a word from the list of viable words */
	srand(time(NULL));
	int randomInt = rand() % (wordList.size() - 1);
	
	/** Create an empty word of the correct length for the user to see their 
	 *  guessing progress.
	 */
	string wordToGuess = wordList.at(randomInt);
	vector<char> currWord;
	for(int i = 0; i < wordLength - 1; i++){
	    currWord.push_back('_');
	}
	
	/* While the game is not over, have the user guess a char or a word */
	char prompt = '';
	bool gameOver = false;
    while (!gameOver) {
        
        /* Print the current status of the word to be guessed */
        for(auto i = currWord.begin(); i != currWord.end(); i++){
            std::cout << *i;
        }
        
        /* Prompt the user for input */
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