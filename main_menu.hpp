#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

enum TypeOfScreen {menu_screen, field_screen, exchange_screen};

TypeOfScreen MainMenu(sf::RenderWindow& window) {
  sf::Texture exit_, exchange_, my_farm_;
  exit_.loadFromFile("../data/pics_for_menu/exit.png");
  exchange_.loadFromFile("../data/pics_for_menu/exchange.png");
  my_farm_.loadFromFile("../data/pics_for_menu/my_farm.png");
  sf::Sprite menu1(exit_), menu2(exchange_), menu3(my_farm_);
  bool isMenu = 1;
  int menuNum = 0;
  menu1.setPosition(100, 200);
  menu2.setPosition(100, 400);
  menu3.setPosition(100, 600);
  
  while (isMenu) {
    menu1.setColor(sf::Color::White);
    menu2.setColor(sf::Color::White);
    menu3.setColor(sf::Color::White);
    menuNum = 0;
    window.clear(sf::Color(100, 100, 100));
  sf::Event event;
  while (window.pollEvent(event)) { // смотрим поочередно на все события, которые у нас произошли
    if (menu1.getTextureRect().contains(sf::Mouse::getPosition(window))) { 
      menu1.(sf::Color::Blue);
      menuNum = 1; 
    }
	  if (menu2.getTextureRect().contains(sf::Mouse::getPosition(window))) { 
      menu2.setColor(sf::Color::Blue); 
      menuNum = 2; 
    }
		if (menu3.getTextureRect().contains(sf::Mouse::getPosition(window))) { 
      menu3.setColor(sf::Color::Blue); 
      menuNum = 3; 
    }
    if (event.type == sf::Event::KeyPressed) {
      isMenu = false;
    }
    if (event.type == sf::Event::MouseButtonPressed) {
      isMenu = false;
      switch(menuNum) {
        case 2:
          return exchange_screen;
        case 3:
          return field_screen;
        default:
          return menu_screen;
      }
    }
  }
  window.draw(menu1);
  window.draw(menu2);
  window.draw(menu3);
  window.display();
  }
  return menu_screen;
}