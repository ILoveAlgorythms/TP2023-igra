#include "animal.hpp"
#include "farm.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

int main() {
  #pragma warning (add screen size to config file)
  sf::RenderWindow window(sf::VideoMode(1600, 900), "SAD FARM");
  //sounds:
  sf::SoundBuffer soundBuffer;
  if (!soundBuffer.loadFromFile("../data/audio/543.ogg")) {
    throw "no file";
  }
  sf::Sound sound;
  sound.setBuffer(soundBuffer);

  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        window.close();
      }
      if (event.type == sf::Event::MouseButtonPressed) {
        sound.play();
        sound.setPitch(1.2);
      }
    }

    window.clear();
    window.display();
  }
  return 0;
}

