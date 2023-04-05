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

// void Animal::Graze(float probability=1.0) {
//   std::srand(std::time(nullptr));
//     if (probability > (std::rand() / RAND_MAX)) {
//       Pos.first += (std::rand() / RAND_MAX - 0.5) * max_step_;
//       Pos.second += (std::rand() / RAND_MAX - 0.5) * max_step_;
//     }
// }
