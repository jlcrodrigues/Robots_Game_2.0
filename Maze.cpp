#include "Maze.h"

using namespace std;

Maze:: Maze(){
    this -> numRows = 10;
    this -> numCols = 10;
    cout << "default constructor maze" << endl;
}

Maze:: Maze(int numRows, int numCols){
    this -> numRows = numRows;
    this -> numCols = numCols;
    cout << "non-default constructor maze" << endl;
}

void Maze:: test(){
    cout << "OLA DO MAZE"<< endl;
}

int Maze:: getnumCols() const{
    return numCols;
}
