#pragma once
#include <unordered_map>
#include <vector>
enum ResourceType {
  Money, Eggs, Meat, Milk
};

class Resources {
 private:
  std::unordered_map<ResourceType, int> res_ = {
    {Money, 0},
    {Eggs, 0},
    {Meat, 0},
    {Milk, 0}
  };

 public:
  Resources() = default;
  ~Resources() = default;
  Resources(ResourceType res, int amount) { res_[res] = (amount); }
  Resources& operator=(const Resources& r) = default;

  void PayMoney(int x);
  void GiveEggs(int x);
  void GiveMeat(int x);
  void GiveMilk(int x);
  int GetMilk();
  int GetEggs();
  int GetMoney();
  void GetMeat(int x);
};

