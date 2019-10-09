/**********************************************************************************
 * Program name: Langston's Ant
 * Author: Steven Owens
 * Date: 10/8/2019
 * Description:  Langston's ant is a two-dimensional universal Turing machine
 *               invented by Chris Langston in 1986.  It is a cellular automation
 *               created on a black and white game board re-created in c++ using
 *               in the console using the char '#' for black and ' ' for white.
 *               The game board implementation is a dynamically allocated 2D array
 *               of characters on the heap. The user is prompted by a console menu
 *               for 5 integers (rows, columns, steps, ant starting row and ant
 *               starting column) as inputs to setup the game parameters.  Once
 *               the user is satisfied with the setup, the simulations continues
 *               until the number of steps reaches 0.  An additional replay feature
 *               allows the user to run the simulation again.
 *********************************************************************************/
#include <iostream>
#include <string>
/*
 * Summary: Provides user input validation by iterating through string and checks if
            all char are digits, if not it sets the isValidInput flag to false and
            breaks the loop since a single since a single failed check means the input
            is invalid.
 * Param: std::string input
 * Returns: bool - true if valid or false if not.
 */
bool isValid(std::string input) {

    bool validInput = true;

    for(unsigned int i = 0; i < input.length(); i++){

        if(!std::isdigit(input.at(i))){
            validInput = false;
            break;
        }
    }

    return validInput;
}
/*
 * Summary: Validates and provides error handling for user input as a string and returns
 *          a fully qualified integer value back to the calling function. Prompts user
            for input following validation failure.
 * Param: std::string input
 * Returns: integer which is validated and converted from a std::string.
 */

/*  cin methods fail, ignore, and cerr adapted from a post by user "int main" on
    20080715 from http://www.cplusplus.com/forum/beginner/2957/ Elected to not use
    cin.fail() and use string input for validation */
int validateInput(std::string input){

    while(input.empty() || !isValid(input)){

        //clears potential error flag on cin from invalid input.
        std::cerr << "Must enter an integer!\n";
        std::cin.clear();
        input = "";  // re-initializes input to empty string ""

        getline(std::cin, input);

    }

    return std::stoi(input);
}