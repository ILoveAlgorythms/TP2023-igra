#include "animal.hpp"
// #include "farm.hpp"
// #include "game.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
// #include <fstream>
#include "main_menu.h"

int main() {
  #pragma warning (add screen size to config file)
  sf::RenderWindow window1(sf::VideoMode(1600, 900), "Main menu of Sad Farm");
	MainMenu(window1);
  sf::RenderWindow window(sf::VideoMode(1600, 900), "SAD FARM"); // делаем окно с заданными размерами и названием
  std::vector<Snail*> tinyLitlleSnails;

  // std::ofstream log ("../.log");

  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) { // смотрим поочередно на все события, которые у нас произошли
      if (event.type == sf::Event::Closed) {
        window.close();
      } else if (event.type == sf::Event::KeyPressed) { // тут вроде по названию понятно
        if (event.key.code == sf::Keyboard::G) {
          delete tinyLitlleSnails.back();
          tinyLitlleSnails.pop_back();
        }
      } else if (event.type == sf::Event::MouseButtonPressed) {
        if (event.mouseButton.button == sf::Mouse::Left) {
          int x = sf::Mouse::getPosition(window).x;
          int y = sf::Mouse::getPosition(window).y;
          tinyLitlleSnails.push_back(new Snail(x, y));
        }
      }
    }
    window.clear(); // стираем окно
    for (auto* i : tinyLitlleSnails) {
      i->Moo();
      i->Graze(9);
      window.draw(i->GetSprite()); // draw -- нарисовать спрайт на окне
    }
    window.display();
  }
  for(auto* i: tinyLitlleSnails) {
    delete i;
  }
  return 0;
}

