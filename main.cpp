#include "animal.hpp"
#include "farm.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
int main() {
  sf::RenderWindow window(sf::VideoMode(800, 450), "SAD FARM");
  //sounds:
  sf::SoundBuffer soundBuffer;
  if (!soundBuffer.loadFromFile("/home/lll/igra/543.ogg")) {
    throw "no file";
  }
  sf::Sound sound;
  sound.setBuffer(soundBuffer);
  sound.setPitch(1.2);

  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        window.close();
      }
      if (event.type == sf::Event::MouseButtonPressed) {
        sound.play();
      }
    }

    window.clear();
    window.display();
  }
  return 0;
}

