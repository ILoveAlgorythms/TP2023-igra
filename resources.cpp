#include "resources.hpp"
#include <stdexcept>

Resources::Resources() {
  res_.resize(Resources::RESORCES_AMOUNT, 0);
}

Resources::Resources(std::vector<int> in) {
  if (in.size() != RESORCES_AMOUNT) {
    throw std::runtime_error("(*)> missmatched size of vector");
    return ;
  }
  res_ = in;
}

Resources& Resources::operator+(const Resources& other) const {
  std::vector<int> tmp(this->res_);
  for (int i = 0; i < tmp.size(); ++i) {
    tmp[i] += other.res_[i];
  }
  Resources ans(tmp);
  return ans;
}

Resources& Resources::operator*(int n) const {
  std::vector<int> tmp(this->res_);
  for (int i = 0; i < tmp.size(); ++i) {
    tmp[i] = tmp[i] * n;
  }
  Resources ans(tmp);
  return ans;
}

Resources& operator*(int n, const Resources& r) {
  Resources ans(r * n);
  return ans;
}

Resources& Resources::operator-(const Resources& other) const {
  return (*this + other * -1);
}

int& Resources::operator[] (ResourceType r) {
  return res_[r];
}

Resources& Resources::operator=(const Resources& other) {
  res_ = other.res_;
  return *this;
}

Resources& Resources::operator+=(const Resources& other) {
  *this = other + *this;
  return *this;
}
Resources& Resources::operator-=(const Resources& other) {
  *this = other - *this;
  return *this;
}
Resources& Resources::operator*=(int n) {
  *this = *this * n;
  return *this;
}
