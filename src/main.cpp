#include "config.h"

const int mapWidth = 24;
const int mapHeight = 24;
// int worldMap[ mapWidth][mapHeight] = {0};
bool exitMaze = false;

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
    {1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 4},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 4, 4}};

void handleMouseInput(sf::RenderWindow &window, int windowWidth,
                      int windowHeight) {
  static sf::Clock clock;
  static bool firstClick = false;
  bool doubleClick = false;

  if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
    sf::Vector2i mousePos = sf::Mouse::getPosition(window);

    int tileSizeX = windowWidth / mapWidth;
    int tileSizeY = windowHeight / mapHeight;

    int offsetX = (windowWidth - tileSizeX * mapWidth) / 2;
    int offsetY = (windowHeight - tileSizeY * mapHeight) / 2;

    int gridX = (mousePos.x - offsetX) / tileSizeX;
    int gridY = (mousePos.y - offsetY) / tileSizeY;

    if (gridX >= 0 && gridX < mapWidth && gridY >= 0 && gridY < mapHeight) {
      if (firstClick && clock.getElapsedTime().asMilliseconds() < 500) {
        doubleClick = true;
        firstClick = false;
      } else {
        firstClick = true;
        clock.restart();
      }

      if (doubleClick) {
        worldMap[gridY][gridX] = 0;  // clear tile on double-click
      } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) ||
                 sf::Keyboard::isKeyPressed(sf::Keyboard::RShift)) {
        worldMap[gridY][gridX] = 4;  // add exit on shift+click
      } else {
        if (worldMap[gridY][gridX] == 0) {
          worldMap[gridY][gridX] = 1;  // add wall on single click
        } else if (worldMap[gridY][gridX] == 1) {
          worldMap[gridY][gridX] = 4;  // change wall to exit
        } else if (worldMap[gridY][gridX] == 4) {
          worldMap[gridY][gridX] = 0;  // clear exit
        }
      }
    }
  } else {
    firstClick = false;  // reset firstClick if button is not pressed
  }
}

void mazeMap(sf::RenderWindow &window, double dirX, double dirY, int posX,
             int posY, int movementX, int movementY, int windowWidth,
             int windowHeight) {
  int tileSizeX = windowWidth / mapWidth;
  int tileSizeY = windowHeight / mapHeight;

  float tileScale = 1.0f;
  float playerScale = 0.5f;

  posX += movementX;
  posY += movementY;

  int offsetX = (windowWidth - tileSizeX * mapWidth) / 2;
  int offsetY = (windowHeight - tileSizeY * mapHeight) / 2;

  // draw the player
  sf::CircleShape player(tileSizeX * playerScale / 2);
  player.setOrigin(player.getRadius(), player.getRadius());
  player.setPosition(offsetX + posX * tileSizeX, offsetY + posY * tileSizeY);
  window.draw(player);

  // draw the gridlines
  for (int y = 0; y <= mapHeight; y++) {
    sf::RectangleShape line(sf::Vector2f(windowWidth, 1));
    line.setFillColor(sf::Color(150, 150, 150));
    line.setPosition(0, offsetY + y * tileSizeY);
    window.draw(line);
  }
  for (int x = 0; x <= mapWidth; x++) {
    sf::RectangleShape line(sf::Vector2f(1, windowHeight));
    line.setFillColor(sf::Color(150, 150, 150));
    line.setPosition(offsetX + x * tileSizeX, 0);
    window.draw(line);
  }

  // draw the tiles
  for (int y = 0; y < mapHeight; y++) {
    for (int x = 0; x < mapWidth; x++) {
      if (worldMap[y][x] > 0) {
        sf::RectangleShape mapTile(
            sf::Vector2f(tileSizeX * tileScale, tileSizeY * tileScale));
        mapTile.setFillColor(sf::Color(213, 211, 211));

        if (worldMap[y][x] == 4) {
          mapTile.setFillColor(sf::Color(0, 255, 0));  // exit tile
        }

        mapTile.setPosition(offsetX + x * tileSizeX, offsetY + y * tileSizeY);
        window.draw(mapTile);
      }
    }
  }
}

void movePlayerBrute(int &posX, int &posY) {
  if (worldMap[posY][posX + 1] == 4 || worldMap[posY + 1][posX] == 4 ||
      worldMap[posY][posX - 1] == 4 || worldMap[posY - 1][posX] == 4) {
    exitMaze = true;
    std::cout << "Exited" << std::endl;
    return;
  }

  if (worldMap[posY][posX + 1] == 0) {
    posX += 1;
  } else if (worldMap[posY + 1][posX] == 0) {
    posY += 1;
  } else {
    while (worldMap[posY][posX - 1] == 0) {
      posX -= 1;
    }
    if (worldMap[posY + 1][posX] == 0) {
      posY += 1;
    }
  }
}

int main() {
  int w = 960, h = 540;
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
        movePlayerBrute(posX, posY);
    }

    oldTime = time;
    time = clock.getElapsedTime().asSeconds();
    int movementX = 0;
    int movementY = 0;

    // movement logic
    if (!exitMaze) {
      movePlayerBrute(posX, posY);
    }

    window.clear();
    handleMouseInput(window, w, h);
    mazeMap(window, dirX, dirY, posX, posY, movementX, movementY, w, h);
    window.display();

    if (exitMaze) {
      window.close();
    }
  }

  return EXIT_SUCCESS;
}
