#include "animal.hpp"
#include "resources.hpp"
#include "farm.hpp"
#include <cmath>

const float kWidth = sf::VideoMode::getDesktopMode().width;
const float kHeight = sf::VideoMode::getDesktopMode().height;

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
 sound_name_(sound_name), texture_name_(texture_name), gathering_timer_(time(NULL)) {
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
  std::pair<int, int> Pos = {soul_.getPosition().x, soul_.getPosition().y};
  if (probability > _dist_(_rng_)) {
    if ((Pos.first - kWidth / 2) * (Pos.first - kWidth / 2) + 
        (Pos.second - kHeight / 2) * (Pos.second - kHeight / 2) > kHeight * kHeight * 0.05) {
      Pos = {Pos.first + copysign(max_step_ + 10, -Pos.first + kWidth / 2),
              Pos.second + copysign(max_step_ + 10, -Pos.second + kHeight / 2)};
    } else {
      Pos = {Pos.first + int(_dist_(_rng_) - 5000) * max_step_ * 0.01, 
             Pos.second + int(_dist_(_rng_) - 5000) * max_step_ * 0.01};
    }
  }
  soul_.setPosition(sf::Vector2f(Pos.first, Pos.second));
}

void Animal::Moo() {
  if (moo_probability_ > double(_dist_(_rng_))) {
    moo_.play();
  }
}

Cow::Cow(int posx, int posy) : Animal(posx, posy, "snail.ogg", "cow1.png"), 
texture_name_("cow"), frame_numbers_(8), performance(std::vector<int> {0, 0, 0, 1}) {
  frames_.resize(frame_numbers_);
  for (int i = 0; i < frame_numbers_; ++i) {
    if(!frames_[i].loadFromFile("../data/texture/" + texture_name_ + std::to_string(i) + ".png")) {
      throw "cant load texture";  
    }
  }
}

Hen::Hen(int posx, int posy) : Animal(posx, posy, "hen.ogg", "hen0.png"), texture_name_("hen"), performance(std::vector<int> {0, 0, 0, 1}) {}

Pig::Pig(int posx, int posy) : Animal(posx, posy, "pig.ogg", "pig0.png"), texture_name_("pig"), performance(std::vector<int> {0, 0, 0, 1}) {}

sf::Sprite& Cow::GetSprite() {
  current_frame_number_ = (current_frame_number_ + 1) % (frame_numbers_ * 10);
  soul_.setTexture(frames_[current_frame_number_ / 10]);
  return soul_;
}

sf::Sprite& Pig::GetSprite() {
  return Animal::GetSprite();
}

Resources Hen::GetResources() {
  auto ans = performance *  difftime(time(NULL), gathering_timer_);
  gathering_timer_ = time(NULL);
  return ans;
}

Resources Pig::GetResources() {
  auto ans = performance *  difftime(time(NULL), gathering_timer_);
  gathering_timer_ = time(NULL);
  return ans;
}

Resources Cow::GetResources() {
  auto ans = performance * difftime(time(NULL), gathering_timer_) ;
  gathering_timer_ = time(NULL);
  return ans;
}