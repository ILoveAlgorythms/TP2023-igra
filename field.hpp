#include "animal.hpp"
// #include "farm.hpp"
// #include "game.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
// #include <fstream>
// #include "main_menu.hpp"
// #include "legacy_snail.hpp"

void Field(sf::RenderWindow& window, Resources& player_res) {
  float width = sf::VideoMode::getDesktopMode().width;
  float height = sf::VideoMode::getDesktopMode().height;
  sf::RectangleShape background(sf::Vector2f(width, height));
  sf::Texture texture_market;
  if (!texture_market.loadFromFile("../data/texture/field.jpg")) { throw std::runtime_error("cant find field.jpg"); }
  background.setTexture(&texture_market);

  std::vector<Animal*> ouranimals;
  enum AnimalType {kCow, kHen, kPig};
  AnimalType nextanimal = kCow;
  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        window.close();
      } else if (event.type == sf::Event::KeyPressed) { // тут вроде по названию понятно
        if (event.key.code == sf::Keyboard::G) {
          delete ouranimals.back();
          ouranimals.pop_back();
        } else if (event.key.code == sf::Keyboard::Enter) {
          window.close();
        } else if (event.key.code == sf::Keyboard::Q) {
          nextanimal = kCow;
        } else if (event.key.code == sf::Keyboard::W) {
          nextanimal = kHen;
        } else if (event.key.code == sf::Keyboard::E) {
          nextanimal = kPig;
        }
      } else if (event.type == sf::Event::MouseButtonPressed) {
        if (event.mouseButton.button == sf::Mouse::Right) {
          int x = sf::Mouse::getPosition(window).x;
          int y = sf::Mouse::getPosition(window).y;
          switch (nextanimal) {
          case kCow:
            ouranimals.push_back(new Cow(x, y));
            break;
          case kHen:
            ouranimals.push_back(new Hen(x, y));
            break;
          case kPig:
            ouranimals.push_back(new Pig(x, y));
            break;
          }
        } else if (event.mouseButton.button == sf::Mouse::Left) {
          int x = sf::Mouse::getPosition(window).x;
          int y = sf::Mouse::getPosition(window).y;
          for (auto i : ouranimals) {
            int posx = i->GetSprite().getPosition().x + i->GetSprite().getTextureRect().width / 2; 
            int posy = i->GetSprite().getPosition().y + i->GetSprite().getTextureRect().height / 2; 
            if ((posx - x) * (posx - x) + (posy - y) * (posy - y) < 9000) {
              player_res += i->GetResources();
            }
          }
          std::cout << "player_res:" << player_res[Money] << "  " << player_res[Eggs] << "  " << player_res[Meat] << "  " << player_res[Milk] << "\n";
        }
      }
    }
    window.clear();
    window.draw(background);
    for (auto* i : ouranimals) {
      i->Moo();
      i->Graze(100);
      window.draw(i->GetSprite());
    }
    window.display();
  }
  for(auto* i: ouranimals) {
    delete i;
  }
}