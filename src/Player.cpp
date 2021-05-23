#include "Player.h"


using namespace std;

Player:: Player(){
    this -> row = 0;
    this -> col = 0;
    this -> symbol = 'H';
    alive = true;
}

Player:: Player(int row, int col, char symbol){
    this -> row = row;
    this -> col = col;
    this -> symbol = symbol;
    alive = true;
}

int Player:: getRow() const{
    return row;
}

int Player:: getCol() const{
    return col;
}

char Player:: getSymbol() const{
    return symbol;
}

bool Player:: isAlive() const{
    return alive;
}

void Player:: setAsDead(){
    alive = false;
}

void Player::setPos(int row, int col)
{
    this -> row = row;
    this -> col = col;
}

bool Player:: move(char movement){
    switch (tolower(movement))
    {
    case 'q':
        col--, row--;
        break;
    case 'w':
        row--;
        break;
    case 'e':
        col++, row--;
        break;
    case 'a':
        col--;
        break;
    case 's':
        break;
    case 'd':
        col++;
        break;
    case 'z':
        col--, row++;
        break;
    case 'x':
        row++;
        break;
    case 'c':
        col++, row++;
        break;
    default:
        cout << "Invalid movement!" << endl
             << endl;
        return 0;
    }
    return 1;
}

bool Player:: drawPlayer(int row, int col) const
{
    if (this -> row == row && this -> col == col)
    {
        cout << symbol;
        return 1;
    }
    return 0;
}