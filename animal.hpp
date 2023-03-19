#pragma once
#include <string>
#include "resources.hpp"
#include <time.h>

enum TypeOfAnimals { Hen, Cow, Pig };

enum Gender { Male, Female };

class Animal {
 public: //
  int time_ = 0;  // время жизни
  int bellyful_ = 0;
  std::string name_;
  Resources anim_res;
  Gender gender = Male;
  
 public:
  virtual void Feed();
  // virtual ~Animal() = default;
};

class Pig : public Animal {};

class Hen : public Animal {};

class Cow : public Animal {};
