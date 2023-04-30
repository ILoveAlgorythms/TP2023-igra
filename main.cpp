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

void GameStart() {
  sf::RenderWindow Play(sf::VideoMode::getDesktopMode(), L"Menu", sf::Style::Fullscreen);
  sf::RectangleShape background(sf::Vector2f(1000, 1000));
  sf::Texture texture_play;
  //
  background.setTexture(&texture_play);

  while (Play.isOpen()) {
    sf::Event event1;
    while (Play.pollEvent(event1)) {
      if (event1.type == sf::Event::KeyPressed) Play.close();
    }
  }
  Play.clear();
  Play.draw(background);
  Play.display();
}
int main() {
  sf::RenderWindow window;
  window.create(sf::VideoMode::getDesktopMode(), L"гама", sf::Style::Default);
  window.setMouseCursorVisible(false);
  float width = sf::VideoMode::getDesktopMode().width;
  float height = sf::VideoMode::getDesktopMode().height;
  sf::RectangleShape background(sf::Vector2f(width, height));
  sf::Texture texture_window;
  texture_window.loadFromFile("../data/texture/menu1.png");
  background.setTexture(&texture_window);
  sf::Font font;
  font.loadFromFile("../data/shrift.ttf");
  sf::Text Titul;
  Titul.setFont(font);
  InitText(Titul, 480, 50, L"Грустная ферма", 150, sf::Color(200, 100, 0), 3);
  sf::String name_menu[] { L"Поле", L"Рынок", L"Выход"};
  GameMenu first_menu(window, 950, 350, 4, name_menu, 100, 120);
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
            case 0: window.close(); //GameStart();
            case 1: window.close();
            // case 1: Market();
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



