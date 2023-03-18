#include "resources.hpp"
#include <stdexcept>

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

Resources& operator*(int n, Resources& r) {
  std::vector<int> tmp(r.res_);
  for (int i = 0; i < tmp.size(); ++i) {
    tmp[i] = tmp[i] * n;
  }
  Resources ans(tmp);
  return ans;
}

Resources& Resources::operator-(const Resources& other) const {
  return (*this + other * -1);
}

int& Resources::operator[] (ResourceType r) {
  return res_[r];
}
