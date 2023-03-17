#pragma once
#include "resources.hpp"
#include "farm.hpp"
#include <vector>
class Market {
 private:
  float bonus_ = 1.0;
 public:
  Market() = default;
  ~Market() = default;

  void UpdateBonus(float f);
  std::vector<Animal*> GetTrades();
};
