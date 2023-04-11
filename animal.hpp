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

enum TypeOfAnimals { Hen, Cow, Pig };

enum Gender { Male, Female };

class Animal {
 public: //
  int time_ = 0;
  int bellyful_ = 0;
  std::string name_;
  Resources anim_res_;
  Gender gender = Male;
  
 public:
  Animal(int posx = -1, int posy = -1);
  virtual void Feed();
  virtual ~Animal() = default;
};

class Pig : public Animal {
  //anim_res.res_[Money] = 50;
};

class Hen : public Animal {
  //anim_res.res_[Money] = 10; 
};

class Cow : public Animal {
  // anim_res.res_[Money] = 100;
  // anim_res.res_[Meat] = 80;
  
};

class Snail : public Animal {
 public:
  Snail(int posx=-1, int posy=-1) : Animal(), _rng_(_dev_()), _dist_(0, 10000) { // устанавливаем диапазон рандомайзера
    if(!sound_buffer_.loadFromFile("../data/audio/" + sound_name_)) {
      throw "cant load sound";
    }
    moo_.setBuffer(sound_buffer_); // устанавливаем, что будем проигрывать

    if(!skin_.loadFromFile("../data/texture/" + texture_name_)) {
      throw "cant load texture";
    }
    soul_.setTexture(skin_); // устанавливаем текстуру спрайту
    Pos.first = posx;
    Pos.second = posy;
    if (posx == -1) { // если позиция не задана, делаем рандомную
      Pos.first = 100 + int(_dist_(_rng_)) / 90;
      Pos.second = 100 + int(_dist_(_rng_)) / 90;
    }
  }

  void Graze(unsigned long int probability=100) { // probability form 0 to 100
    int x;
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
  std::pair<int, int> Pos;
 private:
  sf::SoundBuffer sound_buffer_; // сюда загружается звук (файлом), буфер
  std::string sound_name_ = "543.ogg";
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
