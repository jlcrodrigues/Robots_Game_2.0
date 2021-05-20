#include "Post.h"


using namespace std;

Post:: Post(){
    this -> row = 0;
    this -> col = 0;
    this -> type = '+';
}

Post:: Post(int row, int col, char type){
    this -> row = row;
    this -> col = col;
    this -> type = type;
}

void Post:: test(){
    cout << "OLA DO POST"<< endl;
}

int Post:: getRow() const{
    return row;
}

int Post:: getCol() const{
    return col;
}

char Post:: getSymbol() const{
    return type;
}

bool Post:: isElectrified() const{
    if (type=='+'){
        return false;
    }
    else{
        return true;
    }
}