#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

void MainMenu(sf::RenderWindow& window) {
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
 
		if (sf::IntRect(100, 200, 100, 30).contains(sf::Mouse::getPosition(window))) { menu1.setColor(sf::Color::Black); menuNum = 1; }
		if (sf::IntRect(100, 400, 100, 30).contains(sf::Mouse::getPosition(window))) { menu2.setColor(sf::Color::Black); menuNum = 2; }
		if (sf::IntRect(100, 600, 100, 30).contains(sf::Mouse::getPosition(window))) { menu3.setColor(sf::Color::Black); menuNum = 3; }
 
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			window.close(); isMenu = false;
		}
		window.draw(menu1);
		window.draw(menu2);
		window.draw(menu3);
		window.display();
	}
}