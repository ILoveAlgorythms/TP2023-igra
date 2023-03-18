#include <iostream>

struct test {
  int q = 5;
  ~test() {
    std::cout <<"die\n";
  }
};

int main()
{
  test* b;
  if (true) {
    test a;
    b = &a;
  }
  if (b == nullptr) {
    std::cout << "lsls";
  }
  std::cout << b;
  return 0;
}
