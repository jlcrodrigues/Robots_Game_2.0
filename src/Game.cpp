#include "Game.h"
#include "Maze.h"
#include "Player.h"
#include "Post.h"
#include "Robot.h"

using namespace std;

Game::Game(const std::string &file_name)
{
    char column; //stores the column being read´

    ifstream maze_file;
    maze_file.open(file_name); //opens the file

    int width, height; //maze dimensions

    maze_file >> height;

    maze_file.get(column);
    while (column < '0' || column > '9') //ignores the non-digit characters
        maze_file.get(column);
    maze_file.unget();

    maze_file >> width;

    maze.setnumRows(height);
    maze.setnumCols(width);

    maze_file.get(column); //reads '\n' so it can be ignored

    for (int i = 0; i < height; i++) //iterates the lines
    {
        for (int j = 0; j < width; j++) //iterates the columns
        {
            maze_file.get(column); //reads a character
            if (column == '+' || column == '*')
            {
                maze.addPost(i, j, column);
            }
            else if (column == 'r' || column == 'R')
            {
                robots.push_back(Robot(i, j));
            }
            else if (column == 'H')
            {
                player.setPos(i, j);
            }
        }
        maze_file.get(column); //reads '\n' so it can be ignored
    }
    maze_file.close();
}

void Game::showGameDisplay() const
{
    for (int row = 0; row < maze.getnumRows(); row++)
    {
        for (int col = 0; col < maze.getnumCols(); col++)
        {
            if (!maze.drawPost(row, col) && !player.drawPlayer(row, col) && !drawRobot(row, col))
                cout << ' ';
        }
        cout << '\n';
    }
}

bool Game::drawRobot(int row, int col) const
{
    for (size_t i=0; i < robots.size();i++) 
    {
        if (robots.at(i).getCol() == col && robots.at(i).getRow() == row)
        {
            cout << robots.at(i).getSymbol();
            return 1;
        }
    }
    return 0;
}

void Game::moveRobots()
{
    for (size_t i=0; i < robots.size();i++)
    {
        robots.at(i).move(player.getCol(), player.getRow());
    }
}

bool Game:: collide(Robot &robot, Player &player){
    return (robot.getCol()==player.getCol() && robot.getRow()==player.getRow());
}

void Game::test()
{
    cout << "OLA DO GAME" << endl;
    //cout << maze.numCols << endl;
}


bool Game::play()
{
    char move;
    while (1) //while
    {   
        showGameDisplay();
        do
        {   
            cout << "\nPerform a movement: ";
            cin >> move;
            cout << endl;
            cin.ignore(100000, '\n');
            if (cin.fail() && cin.eof()) //check if ctrl + z was pressed
            {
                cout << "EXIT";
                return 0;
            }
        } while (!player.move(move));
        moveRobots();
        
        for (size_t i=0; i < robots.size();i++){    //check if player and robot collide
            if (collide(robots.at(i),player)){
                player.setAsDead();
                showGameDisplay();
                return 0;
            }
        }
    }
}