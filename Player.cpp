#include "Player.h"


using namespace std;

Player:: Player(){
    this -> row = 0;
    this -> col = 0;
    this -> symbol = 'h';
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
void Player:: test(){
    cout << "OLA DO PLAYER"<< endl;
}
