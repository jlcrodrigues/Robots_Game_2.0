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
                player.move(j, i);
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
            if (!maze.drawPost(row, col) && !drawRobot(row, col) && !player.drawPlayer(row, col))
                cout << ' ';
        }
        cout << '\n';
    }
}

bool Game::drawRobot(int row, int col) const
{
    for (Robot robot : robots) //iterate through the posts
    {
        if (robot.getCol() == col && robot.getRow() == row)
        {
            cout << robot.getSymbol();
            return 1;
        }
    }
    return 0;
}

void Game::test()
{
    cout << "OLA DO GAME" << endl;
    //cout << maze.numCols << endl;
}

bool Game::play()
{
    showGameDisplay();
}