#include "farm.hpp"

void Base::GetAnimal(std::string s, TypeOfAnimals t) {
  Pets_[s] = t;
}

void Base::RemoveAnimal(std::string s) {
  Pets_.erase(s);
}

void Base::Build(std::string s, TypeOfBuildings t) {
  Buildings_[s] = t;
}

void Base::RemoveBuilding(std::string s) {
  Buildings_.erase(s);
}

