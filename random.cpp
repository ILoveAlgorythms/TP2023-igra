#include <random>
#include <iostream>

class Random {
 public:

  int Get() {
    return dist6(rng);
  }
  static Random* GetGame() {
    if (random_ == nullptr) {
      random_ = new Random();
    }
    return random_;
  }

 private:
  static Random* random_;
  Random() : rng(dev()), dist6(1, 6){};
  std::random_device dev;
  std::mt19937 rng;
  std::uniform_int_distribution<std::mt19937::result_type> dist6;
};


int main()
{
  Test MY;
 
    for (int i = 0; i< 10; ++i) {
      std::cout <<  MY.RND()<< std::endl;

    }
}