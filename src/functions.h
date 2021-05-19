#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <fstream>
#include <string>

/**
    Reads an integer and tests if it is valid.
    @param input Integer read passed by reference.
    @return Returns 1 if the input was valid and 0 otherwise.
*/
bool readInteger(int &input);

void displayFile(std::string file_name);

bool displayMenu(std::string file_name, bool& menu, bool& rules, bool& play, bool& winners);

bool displayRules(std::string file_name, bool &menu, bool &rules);

bool displayWinners(bool &menu, bool &winners);

/**
    Asks for a maze number until a valid one is given.
    @return Returns the chosen maze's file name.
*/
std::string chooseMaze();

#endif