#include "functions.h"

using namespace std;

bool readInteger(int &input)
{
    while (1)
    {
        cin >> input;

        if (cin.fail()) // if fail
        {
            if (cin.eof()) // if ctrl-Z is pressed
            {
                cout << "EXIT";
                return 0; //exit
            }
            else // not integer
            {
                cin.clear();
                cin.ignore(100000, '\n');
                cout << "Invalid Input! Try again!\n\n";
            }
        }
        else
            return 1; //input successful
    }
}

void displayFile(string file_name)
{
    ifstream file(file_name);
    cout << endl;
    cout << file.rdbuf();
}

bool displayMenu(string file_name, bool &menu, bool &rules, bool &play, bool &winners)
{
    int menu_option;
    displayFile(file_name);
    do
    {
        cout << "Option: ";
        if (!readInteger(menu_option) || menu_option == 0)
        {
            return 0;
        }
    } while (menu_option > 3 || menu_option < 0); //get a valid option
    if (menu_option == 1) //rules
    {
        menu = false;
        rules = true;
    }
    if (menu_option == 2) //play
    {
        menu = false;
        play = true;
    }
    if (menu_option == 3) //winners
    {
        menu = false;
        winners = true;
    }
    return 1;
}

bool displayRules(string file_name, bool &menu, bool &rules)
{
    int option;
    displayFile(file_name);
    do
    {
        cout << "Option: ";
        if (!readInteger(option))
            return 0;
    } while (option != 0); //waits for a valid input
    menu = true;
    rules = false;
    return 1;
}

bool displayWinners(bool &menu, bool &winners)
{
    int option;
    string file_name;
    file_name = chooseMaze(); //gets a valid maze
    if (file_name == "EXIT")
        return 0;
    else if (file_name == "MENU")
    {
        menu = true;
        winners = false;
        return 1;
    }
    else
        file_name.insert(17, "_WINNERS"); //17 should be 7 if .cpp and .txt are in the same folder
    cout << endl;
    displayFile(file_name);
    cout << "\n\t\t\t\t0) EXIT" << endl;
    do
    {
        cout << "Option: ";
        if (!readInteger(option))
            return 0;
    } while (option != 0); //waits for a valid input
    menu = true;
    winners = false;
    return 1;
}

string chooseMaze()
{
    int maze_number;

    while (1) //main loop
    {
        cout << "\nChoose a maze (input 0 to return to main menu) :  ";

        if (!readInteger(maze_number))
            return "EXIT";

        string file_name;
        if (maze_number == 0)
        {
            cout << endl;  //design purposes
            return "MENU"; // return to menu
        }
        else if (maze_number < 10)
        {
            file_name = "../assets/MAZE_0" + to_string(maze_number) + ".txt"; //formats the fileName string
        }
        else
        {
            file_name = "../assets/MAZE_" + to_string(maze_number) + ".txt"; //formats the fileName string
        }

        ifstream file(file_name); //tries to open an existing file
        if (file.is_open())       //checks if the file exists
            return file_name;
        else
        {
            cout << "That maze does not exist.\n";
        }
    }
}