#ifndef PLAYER_H
#define PLAYER_H



#include <iostream>

class Player
{
public:
   Player();
   Player(int row, int col, char symbol);
   int getRow() const;
   int getCol() const;
   char getSymbol() const;
   bool isAlive() const;
   void setAsDead();
   void move(int x,int y);
   void test();

private:
   int row, col;
   bool alive;
   char symbol;
};

#endif