#pragma once
#include "button.hpp"
#include "farm.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>


class Game { // singleton
 public: 
  static Game* GetGame(Base* base = nullptr) {
    if (game_ == nullptr) {
      game_ = new Game(base);
    }
    return game_;
  }

  void Menu();

  ~Game() {
    delete window;
    delete base;
  }
private:
  static Game* game_;

  Game(Base* base = nullptr) {
    window = new sf::RenderWindow(sf::VideoMode(1600, 900), "SAD FARM");
  }
  Base* base;
  sf::RenderWindow* window;
};

Game* Game::game_{nullptr};
