#pragma once
#include <string>
#include "resources.hpp"
#include <time.h>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <cstdlib> 
// #include <ctime> 
#include <random> 
#include <fstream>
#include <iostream>


class Snail {
 public:
  Snail(int posx=0, int posy=0) : _rng_(_dev_()), _dist_(0, 10000) { // устанавливаем диапазон рандомайзера
    if(!sound_buffer_.loadFromFile("../data/audio/" + sound_name_)) {
      throw "cant load sound";
    }
    moo_.setBuffer(sound_buffer_); // устанавливаем, что будем проигрывать

    if(!skin_.loadFromFile("../data/texture/" + texture_name_)) {
      throw "cant load texture";
    }
    soul_.setTexture(skin_); // устанавливаем текстуру спрайту
    
    soul_.setPosition(sf::Vector2f(posx, posy));
  }
  void Graze(unsigned long int probability=100) { // probability form 0 to 100
    int x;
    std::pair<int, int> Pos = {soul_.getPosition().x, soul_.getPosition().y};
    if (probability > _dist_(_rng_)) {
      for (int i = 0; i < 2; ++i) {
        x = int(_dist_(_rng_) - 5000) * max_step_ * 0.01;
        if ((Pos.first + x > 10) && (Pos.first + x < 800)) {
          Pos.first += x;
        }
        std::swap(Pos.first, Pos.second);
      }
    }
    soul_.setPosition(sf::Vector2f(Pos.first, Pos.second)); // устанавливаем координаты у спрайта
  }
  void Moo() {
    if (moo_probability_ > double(_dist_(_rng_))) {
      moo_.play();
    }
  }
  sf::Sprite& GetSprite() {
    return soul_;
  }
  
  std::string GetTexture() {
    return texture_name_;
  }
  std::string GetSound() {
    return sound_name_;
  }
 private:
  sf::SoundBuffer sound_buffer_; // сюда загружается звук (файлом), буфер
  std::string sound_name_ = "snail.ogg";
  sf::Sound moo_; // через это звук проигрывается
  double moo_probability_ = 1;

  std::string texture_name_ = "snail on the hillside.png";
  double max_step_ = 3;
  sf::Texture skin_; // в эту штуку загружаем изображение
  sf::Sprite soul_; // сущность, которая будет отрисовываться 

  std::random_device _dev_; // штука для рандомайзера
  std::mt19937 _rng_;
  std::uniform_int_distribution<std::mt19937::result_type> _dist_;

};
