#include "animal.hpp"
// #include "farm.hpp"
// #include "game.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
// #include <fstream>
// #include "main_menu.hpp"
#include "field.hpp"
#include "menu2.hpp"
#include "menu2.cpp"




// int main() {
//   #pragma warning (add screen size to config file)
// sf::RenderWindow window(sf::VideoMode(1600, 900), "Main menu of Sad Farm");
//   window.setVerticalSyncEnabled(true);
// 	MainMenu(window);
//   Field(window);
// }

void InitText(sf::Text& mtext, float xpos, float ypos, sf::String str, int size_font = 60, sf::Color menu_text_color = sf::Color::White, int bord = 0, sf::Color border_color = sf::Color::Black) {
  mtext.sf::Text::setCharacterSize(size_font);
  mtext.sf::Transformable::setPosition(xpos, ypos);
  mtext.sf::Text::setString(str);
  mtext.sf::Text::setFillColor(menu_text_color);
  mtext.sf::Text::setOutlineThickness(bord);
  mtext.sf::Text::setOutlineColor(border_color);
};

void Market() {
  sf::RenderWindow TradePlatform(sf::VideoMode::getDesktopMode(), L"Рынок", sf::Style::Fullscreen);
  float width = sf::VideoMode::getDesktopMode().width;
  float height = sf::VideoMode::getDesktopMode().height;
  sf::RectangleShape background(sf::Vector2f(width, height));
  sf::Texture texture_market;
  if (!texture_market.loadFromFile("../data/texture/market2.jpg")) return;
  background.setTexture(&texture_market);
  while (TradePlatform.isOpen()) {
    sf::Event event1;
    while (TradePlatform.pollEvent(event1)) {
      if (event1.type == sf::Event::KeyPressed) TradePlatform.close();
    }
    TradePlatform.clear();
    TradePlatform.draw(background);
    TradePlatform.display();
  }
}

void GameStart() {
  sf::RenderWindow Play(sf::VideoMode::getDesktopMode(), L"поле", sf::Style::Fullscreen);
  Field(Play);
}

int main() {
  sf::RenderWindow window;
  window.create(sf::VideoMode::getDesktopMode(), L"гама", sf::Style::Default);
  window.setMouseCursorVisible(false);
  float width = sf::VideoMode::getDesktopMode().width;
  float height = sf::VideoMode::getDesktopMode().height;
  sf::RectangleShape background(sf::Vector2f(width, height));
  sf::Texture texture_window;
  if (!texture_window.loadFromFile("../data/texture/menu1.jpeg")) return 15;
  background.setTexture(&texture_window);
  sf::Font font;
  if (!font.loadFromFile("../data/shrift.ttf")) return 20;
  sf::Text Titul;
  Titul.setFont(font);
  InitText(Titul, 50, 50, L"Sad Farm", 160, sf::Color(100, 100, 100), 2);
  sf::String name_menu[] { L"Поле", L"Рынок", L"Выход"};
  GameMenu first_menu(window, 500, 500, 3, name_menu, 80, 80, font);
  first_menu.setColorTextMenu(sf::Color(230, 100, 0), sf::Color(100, 100, 100), sf::Color(200, 200, 200));
  first_menu.AlignMenu(2);

  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::KeyReleased) {
        if (event.key.code == sf::Keyboard::Up) first_menu.MoveUp();
        if (event.key.code == sf::Keyboard::Down) first_menu.MoveDown();
        if (event.key.code == sf::Keyboard::Return) {
          switch (first_menu.getSelectedMenuNumber()) {
            case 0: GameStart();
            // case 1: window.close();
            case 1: Market();
            case 2: window.close();
          }
        }
      }
    }
    window.clear();
    window.draw(background);
    window.draw(Titul);
    first_menu.draw();
    window.display();
  }
}



