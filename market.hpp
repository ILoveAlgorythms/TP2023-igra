#pragma once
#include "resources.hpp"
#include "farm.hpp"
#include "animal.hpp"
#include <vector>
#include <ctime>

class Market {
 public:
  Market() = default;
  ~Market() = default;

  void UpdateBonus(float f);
  std::vector<std::pair<Animal&, int>> GetAnimalPrices();
  std::vector<int> GetResorcesPrices();
  bool BuyAnimal(Animal& a);
  bool SellResource(ResourceType r, int amount);

 private:
  float bonus_ = 1.0;
  std::time_t last_price_update_;
  std::vector<int> resources_prices_;
  void UpdatePrices();
};
