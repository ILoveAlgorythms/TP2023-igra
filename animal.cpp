#include "animal.hpp"
#include "resources.hpp"

void Animal::Feed() {
  if (bellyful_ <= 2) {
    bellyful_ += 2;
  } else {
    bellyful_ = 5;
  }
  happiness_level_ = 5;
}

void Animal::Sell() { // только снимаем с вектора животного, а функция получения денег будет связана с этой за счет паттерна composite
 //снять с вектора
 //получить деньги
}

void Animal::GiveResources() {
  
}