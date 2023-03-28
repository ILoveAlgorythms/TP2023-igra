#pragma once
#include <string>
#include "resources.hpp"
#include <time.h>

enum TypeOfAnimals { Hen, Cow, Pig };

enum Gender { Male, Female };

class Animal {
 public: //
  int time_ = 0;
  int bellyful_ = 0;
  std::string name_;
  Resources anim_res_;
  Gender gender = Male;
  
 public:
  virtual void Feed();
  ~Animal() = default;
};

class Pig : public Animal {
  //anim_res.res_[Money] = 50;
};

class Hen : public Animal {
  //anim_res.res_[Money] = 10; 
};

class Cow : public Animal {
  // anim_res.res_[Money] = 100;
  // anim_res.res_[Meat] = 80;
  
};
