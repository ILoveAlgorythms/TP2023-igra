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
