/*
BFS - Breadth First Search

- first search horzontaliy
- hold searched tiles in queue

*/

#include "bfs.h"

#include <iostream>
#include <queue>
#include <tuple>
#include <vector>

#include "config.h"

//vector<pair<int, int>> 
void bfs(int worldMap[25][24], int posX, int posY,
                           int mapWidth, int mapHeight) {
  // Directions for moving: right, down, left, up
  int directions[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

  // queue for BFS
  queue<Node> q;
  q.push({posX, posY, {{posX, posY}}});

  // visited array, keep track of visited nodes
  bool visited[25][24] = {false};
  visited[posX][posY] = true;

  // mark start pos as visited
  // worldMap[posX][posY] = 5;

  while (!q.empty()) {
    Node current = q.front();
    cout << "Q popped" << endl;
    q.pop();

    // check if exit
    if (worldMap[current.x][current.y] == 4) {
      cout << "Found Exit" << endl;
      return; //current.path;
    }

    // explore neighbors
    for (auto& dir : directions) {
      int newX = current.x + dir[0];
      int newY = current.y + dir[1];

      // check if new pos within bounds and not visited
      if (newX >= 0 && newX < mapWidth && newY >= 0 && newY < mapHeight &&
          !visited[newX][newY] &&
          (worldMap[newX][newY] == 0 || worldMap[newX][newY] == 4)) {
        visited[newX][newY] = true;
        if (worldMap[newX][newY] != 4) {
          worldMap[newX][newY] = 5;
        }

        vector<pair<int, int>> newPath = current.path;
        newPath.push_back({newX, newY});
        q.push({newX, newY, newPath});
      }
    }
  }

  // if no path found, return
  return ;
}