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
#include <vector>

// enum TypeOfAnimals { Hen, Cow, Pig };

enum Gender { Male, Female };

class Animal {
 public:
  Animal(int posx, int posy, std::string sound, std::string texture);
  virtual void Feed();
  virtual ~Animal() = default;
  virtual void Graze(unsigned long int probability);
  virtual void Moo();
  virtual sf::Sprite& GetSprite() { return soul_; }
  virtual std::string GetTexture() { return texture_name_; }
  virtual std::string GetSound() { return sound_name_; }

 protected:
  int time_ = 0;
  int bellyful_ = 0;
  std::string name_;
  Resources anim_res_;
  Gender gender_ = Male;
  sf::SoundBuffer sound_buffer_; // сюда загружается звук (файлом), буфер
  std::string sound_name_;
  sf::Sound moo_; // через это звук проигрывается
  double moo_probability_ = 1;

  std::string texture_name_;
  double max_step_ = 3;
  sf::Texture skin_; // в эту штуку загружаем изображение
  sf::Sprite soul_; // сущность, которая будет отрисовываться 

  std::random_device _dev_; // штука для рандомайзера
  std::mt19937 _rng_;
  std::uniform_int_distribution<std::mt19937::result_type> _dist_;
};

class Pig : public Animal {
  //anim_res.res_[Money] = 50;
};

class Hen : public Animal {
  //anim_res.res_[Money] = 10; 
};

class Cow : public Animal {
 public:
  Cow(int posx, int posy);
  sf::Sprite& GetSprite() override;
 private:
  // std::string texture_name_ = "cow1.png";
  // std::string sound_name_ = "cow.wav";
  std::vector<sf::Texture> frames_;
  int current_frame_number_ = 0;
};
