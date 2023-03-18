#include "animal.hpp"
#include "resources.hpp"
#include "farm.hpp"

void Animal::Feed() {
  if (bellyful_ <= 2) {
    bellyful_ += 2;
  } else {
    bellyful_ = 5;
  }
}

// тут много чего было, но мы вроде решили делать делать это в Base