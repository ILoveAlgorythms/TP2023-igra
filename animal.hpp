#pragma once
#include <string>
#include "resources.hpp"
#include <time.h>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <cstdlib> 
// #include <ctime> 
#include <random> 

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
  Snail() : Animal(), _rng_(_dev_()), _dist_(0, 100){
    std::srand(std::time(nullptr));
    if(!sound_buffer_.loadFromFile("../data/audio/" + sound_name_)) {
      throw "cant load sound";
    }
    moo_.setBuffer(sound_buffer_);

    if(!skin_.loadFromFile("../data/texture/" + texture_name_)) {
      throw "cant load texture";
    }
    soul_.setTexture(skin_);
  }
  void Graze(unsigned long int probability=100) { // probability form 0 to 100
  int x;
    if (probability > _dist_(_rng_)) {
      for (int i = 0; i < 2; ++i) {
        x = (_dist_(_rng_) - 50) * max_step_;
        if ((Pos.first + x > 10) && (Pos.first + x < 800)) {
          Pos.first += x;
        }
        std::swap(Pos.first, Pos.second);
      }
    }
    soul_.setPosition(sf::Vector2f(Pos.first, Pos.second));
    // soul_.setScale(sf::Vector2f(Size.first, Size.second));
  }
  void Moo() {
    if (moo_probability_ > (_dist_(_rng_))) {
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
  std::pair<int, int> Pos {100, 100};
  std::pair<int, int> Size {384, 281};
 private:
  sf::SoundBuffer sound_buffer_;
  std::string sound_name_ = "543.ogg";
  sf::Sound moo_;
  double moo_probability_ = 0.2;

  std::string texture_name_ = "snail on the hillside.png";
  double max_step_ = .0;
  sf::Texture skin_;
  sf::Sprite soul_; // beter call

  std::random_device _dev_;
  std::mt19937 _rng_;
  std::uniform_int_distribution<std::mt19937::result_type> _dist_;

};
