#pragma once
#include <unordered_map>
#include "animal.hpp"
enum ResourceType {
  Money, Eggs, Meat, Milk
};

class Trade {
 private:
  std::unordered_map<ResourceType, int> res_ = {
    {Money, 0},
    {Eggs, 0},
    {Meat, 0},
    {Milk, 0}
  };
  Animal* animal_ = nullptr;

 public:
  Trade() = default;
  ~Trade() = default;
  Trade(ResourceType res, int amount) { res_[res] = (amount); }
  Trade& operator=(const Trade& r) = default;

};
