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

Animal(int posx = -1, int posy = -1) : Animal(), _rng_(_dev_()), _dist_(0, 10000) { // устанавливаем диапазон рандомайзера
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

// void Animal::Graze(float probability=1.0) {
//   std::srand(std::time(nullptr));
//     if (probability > (std::rand() / RAND_MAX)) {
//       Pos.first += (std::rand() / RAND_MAX - 0.5) * max_step_;
//       Pos.second += (std::rand() / RAND_MAX - 0.5) * max_step_;
//     }
// }
