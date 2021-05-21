#ifndef MAZE_H
#define MAZE_H



#include <iostream>
#include "Post.h"
#include <vector>



class Maze
{
public:
   Maze();
   Maze(int numRows, int numCols);
   bool addPost(const Post &post, const int &x, const int &y, const  int getnumRows()) const;
   int getnumCols() const;
   void test();
   // other methods
private:
   int numRows, numCols;
   std:: vector<Post> posts;
};

#endif