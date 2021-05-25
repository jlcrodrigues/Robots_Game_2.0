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
            if (column == '+' || column == '*' || column == 'O')
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
            if (!player.drawPlayer(row, col) && !drawRobot(row, col))
                cout << maze.charPost(row, col);
        }
        cout << '\n';
    }
}

bool Game::drawRobot(int row, int col) const
{
    for (size_t i = 0; i < robots.size(); i++)
    {
        if (robots.at(i).getCol() == col && robots.at(i).getRow() == row)
        {
            cout << robots.at(i).getSymbol();
            return 1;
        }
    }
    return 0;
}

bool Game::hasWon()
{
    int dead_robots = 0;
    for (int i = 0; i < robots.size(); i++)
    {
        if (!robots.at(i).isAlive())
            dead_robots++;
    }
    cout <<  dead_robots << endl;
    if (dead_robots == robots.size())
        return 1;

    if (maze.charPost(player.getRow(), player.getCol()) == 'O')
        return 1;
    return 0;
}

void Game::moveRobots()
{
    for (size_t i = 0; i < robots.size(); i++)
    {
        char post;
        Robot temp = robots.at(i);
        robots.at(i).move(player.getCol(), player.getRow());
        post = maze.charPost(robots.at(i).getRow(), robots.at(i).getCol());
        if (post == '+')
        {
            robots.at(i).setAsDead();
        }
        if (post == '*')
        {
            robots.at(i) = temp;
            robots.at(i).setAsDead();
        }
        collide(robots.at(i));
    }
}

void Game::collide(Robot &robot)
{
    for (size_t i = 0; i < robots.size(); i++)
    {
        if (robot.getCol() == robots.at(i).getCol() &&
            robot.getRow() == robots.at(i).getRow() &&
            robot.getID() != robots.at(i).getID())
        {
            robot.setAsDead();
            robots.at(i).setAsDead();
        }
    }
}

bool Game::collide(Robot &robot, Player &player)
{
    return (robot.getCol() == player.getCol() && robot.getRow() == player.getRow());
}

void Game::test()
{
    cout << "OLA DO GAME" << endl;
    //cout << maze.numCols << endl;
}

bool Game::play()
{
    char move;
    string game_state;
    while (1) //while
    {
        showGameDisplay();
        Player temp_player = player;
        char post;
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
        //verificar move player
        post = maze.charPost(player.getRow(), player.getCol());
        if (post == '+')
        {
            player = temp_player;
            cout << "Invalid movement!\n";
            continue;
        }
        if (post == '*')
        {
            game_state = "lost";
        }
        moveRobots();

        for (size_t i = 0; i < robots.size(); i++)
        { //check if player and robot collide
            if (collide(robots.at(i), player))
            {
                player = temp_player;
            }
        }

        if (hasWon())
        {
            return 1;
        }

        if (game_state == "lost")
        {
            game_state = "lost";
            player.setAsDead();
            showGameDisplay();
            return 0;
        }
    }
}