#include "Player.h"


using namespace std;

Player:: Player(){
    this -> row = 0;
    this -> col = 0;
    this -> symbol = 'H';
    alive = true;
    cout << "default constructor player" << endl;
}

Player:: Player(int row, int col, char symbol){
    this -> row = row;
    this -> col = col;
    this -> symbol = symbol;
    alive = true;
    cout << "non-default constructor player" << endl;
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

void Player:: move(int x,int y){
    this -> row += x;
    this -> col += y;
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