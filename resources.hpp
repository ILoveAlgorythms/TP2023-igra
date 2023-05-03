#pragma once

#include <vector>
enum ResourceType {
  Money, Eggs, Meat, Milk
};

struct Resources {
 public:
  static const size_t RESORCES_AMOUNT = 4;
  std::vector<int> res_;
 public:
  Resources();
  Resources(const Resources& r) = default;
  Resources(std::vector<int> in);
  ~Resources() = default;
  Resources& operator=(const Resources& other);
  Resources  operator+(const Resources& other) const;
  Resources  operator-(const Resources& other) const;
  Resources  operator*(int n) const;
  Resources& operator+=(const Resources& other);
  Resources& operator-=(const Resources& other);
  Resources& operator*=(int n);
  friend Resources& operator*(int n, Resources& r);
  int& operator[] (ResourceType r);
};
