#ifndef BFS_H
#define BFS_H

#include <iostream>
#include <queue>
#include <vector>
#include <tuple>

using namespace std;

//node for BFS
struct Node {
    int x, y;
    vector<pair<int, int>> path;
};

//vector<pair<int, int>> 
void bfs(int worldMap[25][24], int posX, int posY, int mapWidth, int mapHeight);


#endif  //BFS_H