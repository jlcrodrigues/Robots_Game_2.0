#include "Maze.h"
#include "Post.h"

using namespace std;

Maze:: Maze(){
    this -> numRows = 10;
    this -> numCols = 10;
}

Maze:: Maze(int numRows, int numCols){
    this -> numRows = numRows;
    this -> numCols = numCols;
}

void Maze:: test(){
    cout << "OLA DO MAZE"<< endl;
}

void Maze:: addPost(int row, int col, char type)
{
    posts.push_back(Post(row, col, type));
}

char Maze:: charPost(int row, int col) const
{
    for (size_t i=0; i < posts.size();i++) //iterate through the posts
    {
        if (posts.at(i).getCol() == col && posts.at(i).getRow() == row)
        {   
            return posts.at(i).getSymbol() ;
        }
    }
    return ' ';
}


int Maze:: getnumCols() const{
    return numCols;
}

int Maze:: getnumRows() const{
    return numRows;
}

void Maze:: setnumCols(int numCols) {
    this -> numCols = numCols;
}

void Maze:: setnumRows(int numRows) {
    this -> numRows = numRows;
}
