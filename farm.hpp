#pragma once
#include <vector>
#include <unordered_map>
#include <string>
#include "animal.hpp"
#include "resources.hpp"

enum TypeOfBuildings { Bathhouse, House };

struct Base {
 public:
  std::unordered_map<std::string, Animal*>Pets_; 
  std::unordered_map<std::string, TypeOfBuildings>Buildings_;

 public:
  int test = 0;
  Resources player_res;
  Base();
  ~Base() = default;
  void Build(std::string s, TypeOfBuildings t);
  void GetAnimal(std::string s, Animal* t);
  void RemoveAnimal(std::string s);
  void RemoveBuilding(std::string s);
  void BreedAnimals(std::string son, Animal* a, Animal*b);
  void SellAnimal(std::string s, Animal* t);
  void TakeAnimalRes(Animal* t);
};
