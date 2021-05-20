#ifndef POST_H
#define POST_H

#include <iostream>

class Post
{
public:
   Post();
   Post(int row, int col, char type);
   int getRow() const;
   int getCol() const;
   char getSymbol() const; // get char representation of Post
   bool isElectrified() const;
   void test();
   //other methods
private:
   int row, col;
   char type; // '*' - electrified; '+'- non-electrified
              // other attributes (?)
              // could also have a state, like the robot(?)
};

#endif