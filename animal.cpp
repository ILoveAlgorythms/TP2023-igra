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

Animal::Animal(int posx, int posy) : _rng_(_dev_()), _dist_(0, 10000) { // устанавливаем диапазон рандомайзера
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

void Animal::Graze(unsigned long int probability=100) { // probability form 0 to 100
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

void Animal::Moo() {
  if (moo_probability_ > double(_dist_(_rng_))) {
    moo_.play();
  }
}

sf::Sprite& Animal::GetSprite() {
  return soul_;
}

std::string Animal::GetTexture() {
  return texture_name_;
}
std::string Animal::GetSound() {
  return sound_name_;
}
