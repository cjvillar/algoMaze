#include "config.h"

const int mapWidth = 24;
const int mapHeight = 24;
bool exitMaze = false;
bool startScreen = true;  // start screen flag

// variables for tile colors, easy to find and edit here
sf::Color playerColor(230, 57, 70);
sf::Color playerOutlinecolor(0, 0, 0);

// obsticals
sf::Color wallColor(69, 123, 157);
sf::Color exitColor(168, 218, 220);
// path
sf::Color visitedColor(230, 57, 70);

// background color
sf::Color bgColor(241, 250, 238);

// grid lines
sf::Color gridLines(29, 53, 87);

// 25 x 24
int worldMap[mapWidth][mapHeight] = {
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 4, 4}};

void handleMouseInput(sf::RenderWindow &window, int windowWidth,
                      int windowHeight) {
  if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
    sf::Vector2i mousePos = sf::Mouse::getPosition(window);

    int tileSizeX = windowWidth / mapWidth;
    int tileSizeY = windowHeight / mapHeight;

    int offsetX = (windowWidth - tileSizeX * mapWidth) / 2;
    int offsetY = (windowHeight - tileSizeY * mapHeight) / 2;

    int gridX = (mousePos.x - offsetX) / tileSizeX;
    int gridY = (mousePos.y - offsetY) / tileSizeY;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num4)) {
      worldMap[gridY][gridX] = 4;  // hold 4 key and mouse click to draw exit
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num0)) {
      worldMap[gridY][gridX] = 0;  // hold 0 key and mouse click to remove wall
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1)) {
      worldMap[gridY][gridX] = 1;  // hold 1 key and mouse click to draw wall
    }
  }
}

void mazeMap(sf::RenderWindow &window, double dirX, double dirY, int posX,
             int posY, int movementX, int movementY, int windowWidth,
             int windowHeight) {
  int tileSizeX = windowWidth / mapWidth;
  int tileSizeY = windowHeight / mapHeight;

  float tileScale = 1.0f;
  float playerScale = 1.0f;

  posX += movementX;
  posY += movementY;

  int offsetX = (windowWidth - tileSizeX * mapWidth) / 2;
  int offsetY = (windowHeight - tileSizeY * mapHeight) / 2;

  // draw the tiles
  for (int y = 0; y < mapHeight; y++) {
    for (int x = 0; x < mapWidth; x++) {
      if (worldMap[y][x] > 0) {
        sf::RectangleShape mapTile(
            sf::Vector2f(tileSizeX * tileScale, tileSizeY * tileScale));
        mapTile.setFillColor(sf::Color(wallColor));

        if (worldMap[y][x] == 4) {
          mapTile.setFillColor(sf::Color(exitColor));  // exit tile
        }

        if (worldMap[y][x] == 5) {
          mapTile.setFillColor(sf::Color(visitedColor));  // visited tile
        }

        mapTile.setPosition(offsetX + x * tileSizeX, offsetY + y * tileSizeY);
        window.draw(mapTile);
      }
    }
  }

  // draw the player
  sf::RectangleShape player(
      sf::Vector2f(tileSizeX * playerScale, tileSizeY * playerScale));
  player.setFillColor(sf::Color(playerColor));  // player color
  player.setOutlineColor(sf::Color(playerOutlinecolor));
  player.setOrigin(player.getSize().x / 2, player.getSize().y / 2);
  player.setPosition(offsetX + posX * tileSizeX + tileSizeX / 2,
                     offsetY + posY * tileSizeY + +tileSizeY / 2);

  window.draw(player);

  // draw the gridlines last
  for (int y = 0; y <= mapHeight; y++) {
    sf::RectangleShape line(sf::Vector2f(windowWidth, 1));
    line.setFillColor(sf::Color(gridLines));  // gridline y
    line.setPosition(0, offsetY + y * tileSizeY);
    window.draw(line);
  }
  for (int x = 0; x <= mapWidth; x++) {
    sf::RectangleShape line(sf::Vector2f(1, windowHeight));
    line.setFillColor(sf::Color(gridLines));  // grid line x
    line.setPosition(offsetX + x * tileSizeX, 0);
    window.draw(line);
  }
}

void movePlayerBrute(int &posX, int &posY) {
  if (worldMap[posY][posX + 1] == 4 || worldMap[posY + 1][posX] == 4 ||
      worldMap[posY][posX - 1] == 4 || worldMap[posY - 1][posX] == 4) {
    exitMaze = true;
    std::cout << "Exited" << std::endl;
    return;
  }

//need solution to go up
//if in a bowl
  bool goingUp = false;
  if (worldMap[posY][posX + 1] == 0) {
    posX += 1;  // right
    std::cout << "Going Right!" << std::endl;
  } else if (worldMap[posY + 1][posX] == 0) {
    posY += 1;  //down
    std::cout << "Going Down!" << std::endl;
  } else if ((worldMap[posY][posX + 1] != 1 || 5) && worldMap[posY][posX - 1] == 0) {
    posX -= 1;  //back track left
    std::cout << "Going left!" << std::endl;
  } 

  else if (((worldMap[posY][posX + 1] != 1 || 5) || goingUp) && worldMap[posY - 1][posX] == 0) {
    posY -= 1;//up
    goingUp = true;
    std::cout << "Going Up! " <<  goingUp << std::endl;

  }
  else if(worldMap[posY + 1][posX] == 5){// if the last block it 5  (path) then go left
     posX -= 1;
    std::cout << "stuck!" << std::endl;}
  
    // mark the current position as visited
    worldMap[posY][posX] = 5;
  }

  int main() {
    int w = 528, h = 528;
    int posX = 2, posY = 1;
    double dirX = -1, dirY = 0;

    double time = 0;
    double oldTime = 0;

    sf::RenderWindow window(sf::VideoMode(w, h), "Map Maze Plus Plus");
    window.setFramerateLimit(60);

    sf::Clock clock;
    sf::Time fps;

    while (window.isOpen()) {
      sf::Event event;
      while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) window.close();
        if (event.type == sf::Event::KeyPressed &&
            event.key.code == sf::Keyboard::Escape)
          window.close();
        if (event.type == sf::Event::KeyPressed &&
            event.key.code == sf::Keyboard::Enter && !exitMaze)
          //  movement logic
          if (!exitMaze) {
            bool startScreen = true;  // Start screen flag

            movePlayerBrute(posX, posY);
            // bfs(worldMap, posX, posY, mapWidth, mapHeight);
          }
      }

      if (startScreen) {
        RenderStartScreen(window, startScreen, bgColor);
      } else {
        oldTime = time;
        time = clock.getElapsedTime().asSeconds();
        int movementX = 0;
        int movementY = 0;

        // //  movement logic
        // if (!exitMaze) {
        //   //movePlayerBrute(posX, posY);
        //   bfs(worldMap, posX, posY, mapWidth, mapHeight);
        // } //uncoment for autorun

        // clear window with a white background
        window.clear(sf::Color(bgColor));

        handleMouseInput(window, w, h);
        mazeMap(window, dirX, dirY, posX, posY, movementX, movementY, w, h);
        window.display();

        if (exitMaze) {
          window.close();
        }
      }
    }
    return EXIT_SUCCESS;
  }
