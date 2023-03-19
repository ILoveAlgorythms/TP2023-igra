#pragma once
#include <string>
#include "resources.hpp"

enum TypeOfAnimals { Hen, Cow, Pig };

class Animal {
 public: //
  int time_ = 0;  // время жизни
  int bellyful_ = 0;
  std::string name_;
  Resources anim_r(std::vector<int> = {0, 0, 0, 0});
  
 public:
  virtual void Feed();
  // virtual ~Animal() = default;
};

class Pig : public Animal {};

class Hen : public Animal {};

class Cow : public Animal {};
