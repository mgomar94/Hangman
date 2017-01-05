#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <unordered_set>

using namespace std;

int main(int argc, char* argv[]){

    /* Check to ensure the correct number of inputs is given */
    if(argc != 3) {
        cerr << "Usage: " << argv[0] 
                << " desiredWordLength fileName.txt" << endl;
        return -1;
    }
    
    /* Convert the command line argument to the correct int value */
    int wordLength = *argv[1] - 48;
    
    if(wordLength > 18 || wordLength < 1){
    	cerr << "Please enter a word length between 1 and 18 (inclusive)" 
    			<< endl;
    	return -1;
    }
    
    ifstream in;
    in.open(argv[2]);

    /* Check if input file was actually opened */
    if(!in.is_open()) 
    {
        cout<< "Invalid input file. No file was opened. Please try again.\n";
        return -1;
    }
    
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
    
    /* Randomly select a word from the list of viable words */
	srand(time(NULL));
	int randomInt = rand() % (wordList.size() - 1);
	
	/** Create an empty word of the correct length for the user to see their 
	 *  guessing progress.
	 */
	string wordToGuess = wordList.at(randomInt);
	
	cout << wordToGuess << endl;
	
	string currWord = "";
	for(int i = 0; i < wordLength; i++){
	    currWord.append("_");
	}
 	vector<string> wrongLetters;
 	unordered_set<string> guessedLetters;
	
	string userGuess = "";
	int chancesRemaining = 5;
	cout << "\nYour word is " << wordLength << " letters long" << endl;
	cout << "What is your guess?\n" << endl;
	bool flag = false;

	/* While the game is not over, have the user guess a letter or word */	
	while(chancesRemaining > 0){
	    
	    cout << "You have " << chancesRemaining << " chances remaining\n" << endl;
	    
        /* Print the current status of the word */
        cout << currWord << endl;	    
		
		/* Prompt the user for input */
	    getline(cin, userGuess);
	    
	    /* Determine if the user is guessing a letter or a word */
	    if(userGuess.length() == 1){
	    	
	    	/* Check if this letter has already been guessed */
	    	auto it = guessedLetters.find(userGuess);
	        if(it != guessedLetters.end()){
	            cout << "You already guessed this letter" << endl;
	        }
	        
	        /** If the letter has not yet been guessed, check where it exists
	         *	within the word and replace the '_' with the correct letter
	         *	if it was guessed. Otherwise, add the incorrect guess to the
	         *	set of wrong letters.
	         */
	        else{
	            guessedLetters.insert(userGuess);
	            for(int i = 0; i < wordLength; i++){
	                if(userGuess == string(1,wordToGuess.at(i))){
	                    currWord.at(i) = wordToGuess.at(i);
	                    flag = true;
	                }
	                else if(flag == false && i == wordLength-1){
	                	--chancesRemaining;
	                    wrongLetters.push_back(userGuess);
	                    cout << "\nSorry, your guess was incorrect\n" << endl;
	                }
	            }
	            flag = false;
	            
	            /** If the current status of the word is equal to the word
	             *	to be guessed, then they have correctly guessed the word
	             *	and won the game
	             */
	            if(currWord == wordToGuess){
	                cout << wordToGuess << endl;
	                cout << "Congratulations! You won!" << endl;
	                return 1;
	            }
	        }
	    }
	    
	    /** If they are guessing the word, simply check if the word guessed is
	     *	equal to the word to be guessed. If so, they have won. Otherwise,
	     *	they have incorrectly guessed.
	     */
	    else{
	    	if(userGuess == wordToGuess){
	            cout << "Congratulations! You won!" << endl;
	            return 1;
	        }
	        else{
	        	--chancesRemaining;
	            cout << "\nSorry, your guess was incorrect" << endl;
	        }
	    }
	}
    
    /* If the while loop has ended, they have run out of chances and lost */
    cout << "Game over!" << endl;
    return 0;
}