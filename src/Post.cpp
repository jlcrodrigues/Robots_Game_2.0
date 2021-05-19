#include "Post.h"


using namespace std;

Post:: Post(int row, int col, char type){
    this -> row = row;
    this -> col = col;
    this -> type = type;
}

void Post:: test(){
    cout << "OLA DO POST"<< endl;
}