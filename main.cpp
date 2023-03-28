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
      if (event.type == sf::Event::KeyPressed) {
        window.close();
      }
    }
    window.clear();
    sf::RectangleShape rectangle(sf::Vector2f(400, 400));
    rectangle.setPosition(200, 200);
    rectangle.setFillColor({100,100,100});
    window.draw(rectangle);
    window.display();
  }
  return 0;
}

