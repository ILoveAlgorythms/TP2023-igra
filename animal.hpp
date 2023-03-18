#pragma once
#include <string>

enum TypeOfAnimals { Hen, Cow, Pig };

class Animal {
 private:
  int time_ = 0;  // время жизни
  int bellyful_ = 0;
  std::string name_;
 public:
  virtual void Feed();
  // virtual void Sell();
  // virtual void GiveResources();
  // virtual void Die();
  // virtual ~Animal() = default;
};

class Pig : public Animal {

};

class Hen : public Animal {};

class Cow : public Animal {};
