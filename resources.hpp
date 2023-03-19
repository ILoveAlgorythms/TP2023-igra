#pragma once
#include <vector>
enum ResourceType {
  Money, Eggs, Meat, Milk
};
const size_t RESORCES_AMOUNT = 4;

struct Resources {
 private:
  std::vector<int> res_(4, 0);
 public:
  Resources();
  Resources(const Resources& r);
  Resources(std::vector<int> in);
  ~Resources() = default;
  Resources& operator+(const Resources& other) const;
  Resources& operator-(const Resources& other) const;
  Resources& operator*(int n) const;
  friend Resources& operator*(int n, Resources& r);
  int& operator[] (ResourceType r);
};
