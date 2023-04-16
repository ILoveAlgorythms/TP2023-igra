#include "animal.hpp"
// #include "farm.hpp"
// #include "game.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
// #include <fstream>
#include "main_menu.hpp"
#include "field.hpp"

int main() {
  #pragma warning (add screen size to config file)
  sf::RenderWindow window(sf::VideoMode(1600, 900), "Main menu of Sad Farm");
	MainMenu(window);
  Field(window);
}

