#include "Maze.h"
#include "Post.h"

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

void Maze:: addPost(int row, int col, char type)
{
    posts.push_back(Post(row, col, type));
}

bool Maze:: drawPost(int row, int col) const
{
    for (Post post: posts) //iterate through the posts
    {
        if (post.getCol() == col && post.getRow() == row)
        {
            cout << post.getSymbol();
            return 1;
        }
    }
    return 0;
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
