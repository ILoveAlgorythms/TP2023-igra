#include "animal.hpp"
#include "farm.hpp"
#include "player.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
int main() {
  sf::RenderWindow window(sf::VideoMode(800, 450), "SAD FARM");
  //sounds:
  sf::SoundBuffer soundBuffer;
  if (!soundBuffer.loadFromFile("543.mp3")) {
    throw "no file";
  }

  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        window.close();
      }
      if (event.type == sf::Event::MouseButtonPressed) {
        sf::Sound sound;
        sound.setBuffer(soundBuffer);
        sound.setPitch(1.2);
        sound.play();
      }
    }

    window.clear();
    window.display();
  }
  return 0;
}

