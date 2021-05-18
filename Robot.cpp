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