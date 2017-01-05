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
    

    
    ifstream in;
    in.open(argv[1]);

    /* Check if input file was actually opened */
    if(!in.is_open()) 
    {
        cout<< "Invalid input file. No file was opened. Please try again.\n";
        return -1;
    }
    
    int maxLength = 0;
    
    /* Create a vector of strings to store words of desired length */
    vector<string> wordList;
    std::string word = "";

    /** While there are still words to be read in from the input file,
     *  Check if the next word has a length that matches the desired length
     *  inputted by the user. If so, add it to the vector. Else, continue
     *  reading from the input file.
     */
    while (getline(in, word)) {
        wordList.push_back(word);
        if(word.length() > maxLength){
            maxLength = word.length();
        }
    }
    in.close();
    cout << maxLength << endl;
    return 0;
    
    
}