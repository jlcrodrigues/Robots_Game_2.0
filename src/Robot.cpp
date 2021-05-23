#include "Robot.h"

using namespace std;

int Robot:: robotCounter=0;

Robot:: Robot(){
}

Robot:: Robot(int row, int col){
    this -> row = row;
    this -> col = col;
    this -> id = robotCounter;
    robotCounter ++;
    this-> alive = true;
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
    if (col < x){
        col++;
    }
    else if (col > x){
        col--;
    }
    if (row < y){
        row++;
    }
    else if (row > y){
        row--;
    }
}

void Robot:: setAsDead(){
    alive = false;
}


