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
  virtual Resources GetResources() {}
 protected:
  time_t gathering_timer_; // last gathering
  time_t feeding_timer_; // last feeding
  int bellyful_ = 0;
  std::string name_;
  Resources anim_res_;
  Gender gender_ = Male;
  sf::SoundBuffer sound_buffer_;
  std::string sound_name_;
  sf::Sound moo_; // sound
  double moo_probability_ = 1;

  std::string texture_name_;
  double max_step_ = 3;
  sf::Texture skin_; 
  sf::Sprite soul_; 

  std::random_device _dev_; //for randomizer
  std::mt19937 _rng_;
  std::uniform_int_distribution<std::mt19937::result_type> _dist_;
};

class Pig : public Animal {
 public:
  Pig(int posx, int posy);
  Resources GetResources() override;
  sf::Sprite& GetSprite() override;
 private:
  Resources performance;
  std::string texture_name_;
};


class Hen : public Animal {
 public:
  Hen(int posx, int posy);
  Resources GetResources() override;
 private:
  Resources performance;
  std::string texture_name_;
};

class Cow : public Animal {
 public:
  Cow(int posx, int posy);
  Resources GetResources() override;
  sf::Sprite& GetSprite();
 private:
  Resources performance;
  int frame_numbers_;
  std::string texture_name_;
  std::vector<sf::Texture> frames_;
  int current_frame_number_ = 0;
};
