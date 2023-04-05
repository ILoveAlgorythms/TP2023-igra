#include "animal.hpp"
#include "farm.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

int main() {
  #pragma warning (add screen size to config file)
  sf::RenderWindow window(sf::VideoMode(1600, 900), "SAD FARM");
  //sounds:


  Snail TinyLittleSnail;
  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        window.close();
      }
    }
    TinyLittleSnail.Graze(90);
    // TinyLittleSnail.Moo();

    window.clear();
    window.draw(TinyLittleSnail.GetSprite());
    window.display();
  }
  return 0;
}

