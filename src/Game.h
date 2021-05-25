#ifndef GAME_H
#define GAME_H




#include <iostream>
#include <string>
#include <vector>
#include "Robot.h"
#include "Post.h"
#include "Player.h"
#include "Maze.h"
#include <fstream>


class Game
{
public:
   Game(const std::string &file_name);
   // This constructor should initialize the Maze, the vector of Robots, and the Player,
   // using the chars read from the file
   bool play(); // implements the game loop; returns true if player wins, false otherwise
   bool isValid();
   void test();
   int cols();

private:
   void showGameDisplay() const;
   bool drawRobot(int row, int col) const;
   void moveRobots();    
   bool collide(Robot &robot, Player &player); // check if human and robot collided (and possibly set human as dead)
                                               // other methods, for example:
                                               // to check if player is trying to move to a valid place
                                               // to apply a valid play and check collisions
                                               // to check if two robots collide (and possibly set them as dead)
                                               // etc.
private:
   Maze maze;
   Player player;
   std::vector<Robot> robots;
   //other attributes
};

#endif