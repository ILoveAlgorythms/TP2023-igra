#include "animal.hpp"
#include "resources.hpp"
#include "farm.hpp"

int medim_level_of_bellyful_ = 2;
int max_level_of_bellyful_ = 5;

void Animal::Feed() {
  if (bellyful_ <= medim_level_of_bellyful_) {
    bellyful_ += medim_level_of_bellyful_;
  } else {
    bellyful_ = max_level_of_bellyful_;
  }
}

Animal::Animal(int posx, int posy, std::string sound_name, 
std::string texture_name) : _rng_(_dev_()), _dist_(0, 10000),
 sound_name_(sound_name), texture_name_(texture_name) { // set the range of the randomizer
  std::cout << "hello";
  if(!sound_buffer_.loadFromFile("../data/audio/" + sound_name_)) {
    throw "cant load sound";
  }
  moo_.setBuffer(sound_buffer_); 
      
  if(!skin_.loadFromFile("../data/texture/" + texture_name_)) {
    throw "cant load texture";
  }
  soul_.setTexture(skin_); // set the texture
  
  soul_.setPosition(sf::Vector2f(posx, posy));
}
void Animal::Graze(unsigned long int probability=100) { // probability form 0 to 100
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
  soul_.setPosition(sf::Vector2f(Pos.first, Pos.second)); // set the coordinates of the sprite
}
void Animal::Moo() {
  if (moo_probability_ > double(_dist_(_rng_))) {
    moo_.play();
  }
}


Cow::Cow(int posx, int posy) : Animal(posx, posy, "snail.ogg", "cow1.png") {
  frames_.resize(8);
  for (int i = 0; i < 8; ++i) {
    if(!frames_[i].loadFromFile("../data/texture/cow" + std::to_string(i) + ".png")) {
      throw "cant load texture";
    }
  }
  soul_.setScale(0.2, 0.2);
}

sf::Sprite& Cow::GetSprite() {
  current_frame_number_ = (current_frame_number_ + 1) % (8 * 10);
  soul_.setTexture(frames_[current_frame_number_ / 10]);
  return soul_;
}