#include "config.h"

void RenderStartScreen(sf::RenderWindow &window, bool &startScreen,
                       sf::Color &bgColor) {
  // load default font (Arial)
  sf::Font font;
  if (!font.loadFromFile("assets/RobotoCondensed-VariableFont_wght.ttf")) {
    std::cerr << "Failed to load default font " << std::endl;
    return;
  }

  // text attrib
  sf::Text text;
  text.setFont(font);
  text.setString("AlgoMaze: Press Enter To Start.");
  text.setCharacterSize(32);
  text.setStyle(sf::Text::Bold);
  text.setFillColor(sf::Color(230, 57, 70));

  // instruction text
  sf::Text instText;
  instText.setFont(font);
  instText.setString(
      "Hold 0 and mouse click to remove.\nHold 1 and mouse click to "
      "add wall.\nHold 4 and mouse click to add exit");
  instText.setCharacterSize(22);
  text.setStyle(sf::Text::Bold);
  instText.setFillColor(sf::Color(230, 57, 70));

  // center text
  sf::FloatRect textBounds = text.getLocalBounds();
  float xPos = (window.getSize().x - textBounds.width) / 2;
  float yPos = (window.getSize().y - textBounds.height) / 2;
  text.setPosition(xPos, yPos);

  // place inst text in corner, not sure if this is the right way but works.
  sf::FloatRect instTextBounds = instText.getLocalBounds();
  float xinstPos = (window.getSize().x - instTextBounds.width - 25);
  float yinstPos = (window.getSize().y - instTextBounds.height - 25);
  instText.setPosition(xinstPos, yinstPos);

  // main loop
  while (window.isOpen() && startScreen) {
    sf::Event event;

    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) window.close();

      if ((event.type == sf::Event::KeyPressed) &&
          (event.key.code == sf::Keyboard::Escape))
        window.close();

      if (event.type == sf::Event::KeyPressed &&
          event.key.code == sf::Keyboard::Enter) {
        startScreen = false;
      }
    }

    // show window
    window.clear(sf::Color(bgColor));
    window.draw(text);
    window.draw(instText);
    window.display();
  }
}