#include "animal.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "field.hpp"
#include "menu2.hpp"
#include "menu2.cpp"
#include "resources.hpp"

void FirstMenu(sf::RenderWindow& window, Resources& r, std::vector<Animal*>& ouranimals);
void GameStart(sf::RenderWindow& window, Resources& r, std::vector<Animal*>& ouranimals);
void Market(sf::RenderWindow& window, Resources& r, std::vector<Animal*>& ouranimals);
void Banya(sf::RenderWindow& window, Resources& r, std::vector<Animal*>& ouranimals);

void InitText(sf::Text& mtext, float xpos, float ypos, sf::String str, int size_font = 60, sf::Color menu_text_color = sf::Color::White, int bord = 0, sf::Color border_color = sf::Color::Black) {
  mtext.sf::Text::setCharacterSize(size_font);
  mtext.sf::Transformable::setPosition(xpos, ypos);
  mtext.sf::Text::setString(str);
  mtext.sf::Text::setFillColor(menu_text_color);
  mtext.sf::Text::setOutlineThickness(bord);
  mtext.sf::Text::setOutlineColor(border_color);
};

void Market(sf::RenderWindow& window, Resources& r, std::vector<Animal*>& ouranimals) {
  window.setTitle(L"Рынок");
  window.setMouseCursorVisible(true);

  float width = sf::VideoMode::getDesktopMode().width;
  float height = sf::VideoMode::getDesktopMode().height;
  sf::RectangleShape background(sf::Vector2f(width, height));
  sf::Texture texture_market;
  if (!texture_market.loadFromFile("../data/texture/market2.jpg")) { throw std::runtime_error("market2.jpg"); }
  background.setTexture(&texture_market);

  sf::Font font;
  if (!font.loadFromFile("../data/shrift.ttf")) throw std::runtime_error("cant find font");
  sf::Text Titul;
  Titul.setFont(font);
  std::string s1 = "Money:" + std::to_string(r.res_[0]);
  sf::String sfStr(s1);
  InitText(Titul, 50, 50, sfStr, 160, sf::Color(100, 100, 100), 2);
  sf::String name_menu[] { L"корова 50", L"свинка 20", L"попугай 0", L"в меню"};
  GameMenu first_menu(window, 400, 400, 4, name_menu, 60, 60, font);
  first_menu.setColorTextMenu(sf::Color(230, 100, 0), sf::Color(100, 100, 100), sf::Color(200, 200, 200));
  first_menu.AlignMenu(2);

  while (window.isOpen()) {
    std::string s1 = "Money:" + std::to_string(r.res_[0]);
    sf::String sfStr(s1);
    InitText(Titul, 50, 50, sfStr, 160, sf::Color(100, 100, 100), 2);
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::KeyReleased) {
        if (event.key.code == sf::Keyboard::Up) first_menu.MoveUp();
        if (event.key.code == sf::Keyboard::Down) first_menu.MoveDown();
        if (event.key.code == sf::Keyboard::Return) {
          switch (first_menu.getSelectedMenuNumber()) {
            case 0: 
              r.res_[Money] -= 50;
              ouranimals.push_back(new Cow(int(height * (float(random())/RAND_MAX * 0.4 + 0.3)), 
                                           int(width  * (float(random())/RAND_MAX * 0.4 + 0.3))));
              break;
            case 1: 
              r.res_[Money] -= 20;
              ouranimals.push_back(new Pig(int(height * (float(random())/RAND_MAX * 0.4 + 0.3)), 
                                           int(width  * (float(random())/RAND_MAX * 0.4 + 0.3))));
              break;
            case 2:
              ouranimals.push_back(new Hen(int(height * (float(random())/RAND_MAX * 0.4 + 0.3)), 
                                           int(width  * (float(random())/RAND_MAX * 0.4 + 0.3))));
              break;
            case 3: 
              FirstMenu(window, r, ouranimals);
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

void Banya(sf::RenderWindow& window, Resources& r) {
  window.setTitle(L"Баня");
  float width = sf::VideoMode::getDesktopMode().width;
  float height = sf::VideoMode::getDesktopMode().height;
  sf::RectangleShape background(sf::Vector2f(width, height));
  sf::Texture texture_market;
  if (!texture_market.loadFromFile("../data/texture/banya.jpg")) { throw std::runtime_error("market2.jpg"); }
  background.setTexture(&texture_market);
  sf::Font font;
  if (!font.loadFromFile("../data/shrift.ttf")) throw std::runtime_error("cant find font");
  sf::Text Titul;
  Titul.setFont(font);
  InitText(Titul, 50, 50, L"Баня", 160, sf::Color(100, 100, 100), 2);
  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::KeyReleased) {
        return;
        // FirstMenu(window, r, ouranimals);
      }
    }
    window.clear();
    window.draw(background);
    window.draw(Titul);
    window.display();
  }
}

void GameStart(sf::RenderWindow& window, Resources& r, std::vector<Animal*>& ouranimals) {
  window.setTitle(L"Поле");
  window.setMouseCursorVisible(true);
  Field(window, r, ouranimals);
}

void FirstMenu(sf::RenderWindow& window, Resources& r, std::vector<Animal*>& ouranimals) {
  window.setMouseCursorVisible(false);

  float width = sf::VideoMode::getDesktopMode().width;
  float height = sf::VideoMode::getDesktopMode().height;
  sf::RectangleShape background(sf::Vector2f(width, height));
  sf::Texture texture_window;
  if(!texture_window.loadFromFile("../data/texture/menu1.jpeg")) throw std::runtime_error("cant find menu1.jpeg");
  background.setTexture(&texture_window);

  sf::Font font;
  if (!font.loadFromFile("../data/shrift.ttf")) throw std::runtime_error("cant find font");
  sf::Text Titul;
  Titul.setFont(font);
  InitText(Titul, 50, 50, L"Sad Farm", 160, sf::Color(100, 100, 100), 2);

  sf::String name_menu[] { L"Поле", L"Рынок", L"Баня", L"Выход"};
  GameMenu first_menu(window, 400, 400, 4, name_menu, 80, 80, font);
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
            case 0: GameStart(window, r, ouranimals); break;
            case 1: Market(window, r, ouranimals); break;
            case 2: Banya(window, r); break;
            case 3: window.close();
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
int main() {
  std::vector<Animal*> ouranimals;
  Resources player_res;
  sf::Music music;
  if (!music.openFromFile("../data/audio/music/American Football - Never Meant.ogg")) { std::cout << "cant load music, ну и бог с ним"; }
  music.play();

  sf::RenderWindow window;
  window.create(sf::VideoMode::getDesktopMode(), L"гама", sf::Style::Default);
  window.setVerticalSyncEnabled(true);

  player_res[Money] = 300;
  FirstMenu(window, player_res, ouranimals);
  for(auto* i: ouranimals) {
    delete i;
  }
}



