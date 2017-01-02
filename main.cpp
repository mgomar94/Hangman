#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
#include <string>


int main(int argc, char* argv[]) {

    /* Check to ensure the correct number of inputs is given */
    if(argc != 3) {
        std::cerr << "Usage: " << argv[0] 
                << " desiredWordLength fileName.txt" << std::endl;
        return -1;
    }
    
    
    return 0;
}