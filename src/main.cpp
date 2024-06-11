#include "config.h"

// map
const int mapWidth = 24;
const int mapHeight = 24;

int worldMap[mapWidth][mapHeight] = {
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 4},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 4, 4}};

void mazeMap(sf::RenderWindow &window, double dirX, double dirY, int posX,
             int posY, int movementX, int movementY, int windowWidth,
             int windowHeight) {
  // calc size of each tile based on window dimensions
  int tileSizeX = windowWidth / mapWidth;
  int tileSizeY = windowHeight / mapHeight;

  // tile and player scaling factor
  float tileScale = 1.0f;
  float playerScale = 0.5f;

  // player position based on movement variables
  posX += movementX;
  posY += movementY;

  // offset to center the map within the window
  int offsetX = (windowWidth - tileSizeX * mapWidth) / 2;
  int offsetY = (windowHeight - tileSizeY * mapHeight) / 2;

  for (int y = 0; y < mapHeight; y++) {
    for (int x = 0; x < mapWidth; x++) {
      if (worldMap[y][x] > 0) {
        sf::RectangleShape mapTile(
            sf::Vector2f(tileSizeX * tileScale, tileSizeY * tileScale));
        mapTile.setFillColor(sf::Color(213, 211, 211));

        if (worldMap[y][x] == 4) {
          mapTile.setFillColor(sf::Color(0, 255, 0));
        }  // will be exit

        // calc map tile position based on tile size, index, and offset
        mapTile.setPosition(offsetX + x * tileSizeX, offsetY + y * tileSizeY);

        window.draw(mapTile);
      }
    }
  }

  // player position based on tile size and offset
  sf::CircleShape player(tileSizeX * playerScale / 2);
  player.setOrigin(player.getRadius(), player.getRadius());
  player.setPosition(offsetX + posX * tileSizeX, offsetY + posY * tileSizeY);
  window.draw(player);
}

// player movement functions:
bool exitMaze = false;
void movePlayerBrute(int &posX, int &posY) {
  // check exit condition
  if (worldMap[posY][posX + 1] == 4 || worldMap[posY + 1][posX] == 4 ||
      worldMap[posY][posX - 1] == 4 || worldMap[posY - 1][posX] == 4) {
    exitMaze = true;
    std::cout << "Exited" << std::endl;
    return;
  }
  // attempt right -> down -> left
  if (worldMap[posY][posX + 1] == 0) {
    posX += 1;
  } else if (worldMap[posY + 1][posX] == 0) {
    posY += 1;
  } else {
    // move left until 1
    while (worldMap[posY][posX - 1] == 0) {
      posX -= 1;
    }
    // if blocked move down again until 1 or 4
    if (worldMap[posY + 1][posX] == 0) {
      posY += 1;
    }
  }
}

int main() {
  int w = 960, h = 540;        // window dimensions
  int posX = 2, posY = 1;      // x and y start position
  double dirX = -1, dirY = 0;  // initial direction vector

  double time = 0;     // time of current frame
  double oldTime = 0;  // time of previous frame

  // main window
  sf::RenderWindow window(sf::VideoMode(w, h), "Map Maze Plus Plus");
  window.setFramerateLimit(60);
  sf::Clock clock;
  sf::Time fps;

  // start loop
  while (window.isOpen()) {
    // handle events
    sf::Event event;
    while (window.pollEvent(event)) {
      // close window: exit
      if (event.type == sf::Event::Closed) window.close();

      // escape key: exit
      if (event.type == sf::Event::KeyPressed &&
          event.key.code == sf::Keyboard::Escape)
        window.close();
    }

    // update time variables
    oldTime = time;
    time = clock.getElapsedTime().asSeconds();
    // update player position
    int movementX = 0;  //  x-direction
    int movementY = 0;  //  y-direction

    // movement logic
    if (!exitMaze) {
      movePlayerBrute(posX, posY);
    }

    window.clear();
    // display mini map
    mazeMap(window, dirX, dirY, posX, posY, movementX, movementY, w, h);
    window.display();
    // close when exit
    if (exitMaze) {
      window.close();
    }
  }

  return EXIT_SUCCESS;
}
