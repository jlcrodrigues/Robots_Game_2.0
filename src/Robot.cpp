#include "Robot.h"

using namespace std;

int Robot:: robotCounter=0;

Robot:: Robot(int row, int col){
    this -> row = row;
    this -> col = col;
    this -> id = robotCounter;
    robotCounter ++;
    cout << "non-default robot" << endl;
}

void Robot:: test(){
    cout << "OLA DO ROBOT"<< endl;
    cout << "ID:" << id<< endl;
}

int Robot:: getID() const{
    return id;
}

int Robot:: getRow() const{
    return row;
}

int Robot:: getCol() const{
    return col;
}

char Robot:: getSymbol() const{
    if (alive){
        return 'R';
    }
    else{
        return 'r';
    } 
}

bool Robot:: isAlive() const{
    return alive;
}

void Robot:: move(int x,int y){
    cout << col << row << endl;
    if (col < x)
        col++;
    else if (col > x)
        col--;
    if (row < y)
        row++;
    else if (row > y)
        row--;
    cout << col << row << endl;
}

void Robot:: setAsDead(){
    alive = false;
}


