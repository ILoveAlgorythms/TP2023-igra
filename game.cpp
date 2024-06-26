#include "game.hpp"

void Game::Menu() {
  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        window.close();
      } else if (event.type == sf::Event::KeyPressed) {
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
    window.clear();
    for (auto* i : tinyLitlleSnails) {
      i->Moo();
      i->Graze(9);
      window.draw(i->GetSprite());
    }
    window.display();
  }
}