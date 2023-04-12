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
  sf::SoundBuffer sound_buffer_; // сюда загружается звук (файлом), буфер
  std::string sound_name_;
  sf::Sound moo_; // через это звук проигрывается
  double moo_probability_ = 1;
  std::pair<int, int> Pos;

  std::string texture_name_;
  double max_step_ = 3;
  sf::Texture skin_; // в эту штуку загружаем изображение
  sf::Sprite soul_; // сущность, которая будет отрисовываться 

  std::random_device _dev_; // штука для рандомайзера
  std::mt19937 _rng_;
  std::uniform_int_distribution<std::mt19937::result_type> _dist_;

 public:
  Animal(int posx = -1, int posy = -1);
  virtual void Feed();
  virtual ~Animal() = default;
  void Graze(unsigned long int probability);
  void Moo();
  sf::Sprite& GetSprite();
  std::string GetTexture();
  std::string GetSound();
};

class Pig : public Animal {
public:
  std::string texture_name_ = "";
  std::string sound_name = "";
};

class Hen : public Animal {
public:
  std::string texture_name_ = "";
  std::string sound_name = "";
};

class Cow : public Animal {
public:
  std::string texture_name_ = "";
  std::string sound_name = "";
};

class Snail : public Animal {
 public:
  Snail(int posx = -1, int posy = -1) : Animal(posx, posy) {}
  std::string texture_name_ = "snail on the hillside.png";
  std::string sound_name_ = "543.ogg";
};
