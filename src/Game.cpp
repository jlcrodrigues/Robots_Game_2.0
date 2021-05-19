#include "Game.h"
#include "Maze.h"
#include "Player.h"
#include "Post.h"
#include "Robot.h"

using namespace std;

Game:: Game(const std::string &filename){
    cout << "aqui0" << endl;
    Maze maze1(10,20);
    cout << "aqui1" << endl;
    this -> maze = maze1;
    cout << "aqui2" << endl;
    //Player player(1,2,'H');
    cout << "aqui3" << endl;
    this -> player = Player(1,2,'H');
    cout << "aqui4" << endl;
    Robot robot(1,2);
    cout << "aqui5" << endl;
    vector<Robot> robots;
    robots.push_back(robot);
} 

void Game:: test(){
    cout << "OLA DO GAME"<< endl;
    //cout << maze.numCols << endl;
}


