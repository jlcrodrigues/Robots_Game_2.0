#include "Game.h"
#include "Maze.h"
#include "Player.h"
#include "Post.h"
#include "Robot.h"
#include "functions.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

string MENU_FILE = "../assets/menu.txt";
string RULES_FILE = "../assets/rules.txt";

int main(){
    bool menu = true;
    bool rules = false;
    bool play = false;
    bool winners = false;
    string maze_file;

    while (true)
    {
        if (menu)
        {
            if(!displayMenu(MENU_FILE, menu, rules, play, winners))
                return 0;
        }
        if (rules)
        {
            if(!displayRules(RULES_FILE, menu, rules))
                return 0;
        }
        if (play)
        {
            maze_file = chooseMaze();
            if (maze_file == "EXIT")
                return 0;
            else if (maze_file == "MENU")
            {
                menu = true;
                play = false;
            }
            //criar o objeto Game
        }
        if (winners)
        {
            if(!displayWinners(menu, winners))
                return 0;
        }
    }

    return 0;
}