#include "animal.hpp"
#include "resources.hpp"

void Animal::Feed() {
  if (bellyful <= 2) {
    bellyful += 2;
  } else {
    bellyful = 5;
  }
  // happiness_level_ = 5;
}

void Animal::Sell() { // только снимаем с вектора животного, а функция получения денег будет связана с этой за счет паттерна composite

}

void Animal::GiveResources() {
  
}

//fjhjifchjjifwhjkl