#include "animal.hpp"
// #include "farm.hpp"
// #include "game.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
// #include <fstream>
// #include "main_menu.hpp"
// #include "legacy_snail.hpp"

void Field(sf::RenderWindow& window, Resources& r) {
  float width = sf::VideoMode::getDesktopMode().width;
  float height = sf::VideoMode::getDesktopMode().height;
  sf::RectangleShape background(sf::Vector2f(width, height));
  sf::Texture texture_market;
  if (!texture_market.loadFromFile("../data/texture/field.jpg")) { throw std::runtime_error("cant find field.jpg"); }
  background.setTexture(&texture_market);

  std::vector<Cow*> bigFatCows;
  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        window.close();
      } else if (event.type == sf::Event::KeyPressed) { // тут вроде по названию понятно
        if (event.key.code == sf::Keyboard::G) {
          delete bigFatCows.back();
          bigFatCows.pop_back();
        } else if (event.key.code == sf::Keyboard::Enter) {
          window.close();
        }
      } else if (event.type == sf::Event::MouseButtonPressed) {
        if (event.mouseButton.button == sf::Mouse::Left) {
          int x = sf::Mouse::getPosition(window).x;
          int y = sf::Mouse::getPosition(window).y;
          bigFatCows.push_back(new Cow(x, y));
        }
      }
    }
    window.clear();
    window.draw(background);
    for (auto* i : bigFatCows) {
      i->Moo();
      i->Graze(90);
      window.draw(i->GetSprite());
    }
    window.display();
  }
  for(auto* i: bigFatCows) {
    delete i;
  }
  return;
}