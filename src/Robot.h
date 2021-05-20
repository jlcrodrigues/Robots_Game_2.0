#ifndef ROBOT_H
#define ROBOT_H




#include <iostream>

class Robot
{
public:
   enum State
   {
      ALIVE,
      STUCK,
      DEAD
   };
   Robot(int row, int col);
   int getID() const;
   char getSymbol() const; // get char representation of robot (R if alive, r if dead)
   int getRow() const;
   int getCol() const;
   bool isAlive() const;
   void move(int x,int y);
   void setAsDead();
   void test();
   //other methods
private:
   static int robotCounter; //used to attribute automatically the id to the robots
   int id;
   int row, col;
   bool alive;
   // other attributes (?)
};

#endif
