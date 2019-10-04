//
// Created by Steve Owens on 10/3/19.
//
#include <iostream>
#include <string>

/*  Provides user input validation by taking a string input parameter and
    returns a boolean value. Handles neg numbers "strings" by checking for and
    removing '-' char prior to validation, only allows this special char in the
    first char position.  Iterates through string and checks if all char are digits,
    if not it sets the isValidInput flag to false and breaks the loop since a single
    failed check means the input is invalid */

bool isValid(std::string input) {

    bool validInput = true;

    std::string cleanInput{};

//    if(input.at(0) == '-'){
//
//        cleanInput = input.erase(0,1);
//
//    } else {
//
//        cleanInput = input;
//    }

    cleanInput = input;

    for(unsigned int i = 0; i < cleanInput.length(); i++){

        if(!std::isdigit(cleanInput.at(i)) && validInput){

            validInput = false;
            break;
        }
    }

    return validInput;
}

/*  Validates and provides error handling for user input as a string and returns
    a fully qualified integer value back to the calling function. Prompts user
    for input following validiation failure. */

/*  cin methods fail, ignore, and cerr adapted from a post by user "int main" on
    20080715 from http://www.cplusplus.com/forum/beginner/2957/ Elected to not use
    cin.fail() and use string input for validation */
int validateInput(std::string input){

    while(!isValid(input)){

        //clears potential error flag on cin from invalid input.
        std::cerr << "Must enter an integer!\n";
        std::cin.clear();
        input = "";  // re-initializes input to empty string ""

        getline(std::cin, input);

    }

    return std::stoi(input);
}