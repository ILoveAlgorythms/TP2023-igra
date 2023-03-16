#include <algorithm>
#include <iostream>
#include <vector>
#warning ToDo: разбить на файлы
enum TypeOfPlayer { Woodworker, Tradesman, Herdsman };

enum TypeOfAnimals { Hen, Cow, Pig };

enum TypeOfBuildings { Bathhouse, House };

class Resources {
 private:
  int money_ = 0;
  int eggs_ = 0;
  int meat_ = 0;
  int milk_ = 0;

 public:
  Resources() = default;
  ~Resources() = default;
  Resources& operator=(const Resources& r1) = default;
  Resources(int k) : money_(k), eggs_(0), meat_(0), milk_(0) {}

  void PayMoney(int x);
  void GiveEggs(int x); // возможно нужно возращать как раз x, а у самиз ресурсов убавлять?
  void GiveMeat(int x);
  void GiveMilk(int x);
  void GetMilk(int x);
  void GetEggs(int x);
  void GetMoney(int x);
  void GetMeat(int x);
};

class Player {
 private:
  Resources r_;
  TypeOfPlayer type_ = Woodworker;
};

struct Base {
 private:
  Player p_;
  std::vector<TypeOfAnimals> pets_;
  std::vector<TypeOfBuildings> buildings_;

 public:
  Base() = default;
  ~Base() = default;
  void Build(TypeOfBuildings t); // убрал, потому что мб мы захотим чето ещё делать когда появляется новое здание
  void GetAnimal(TypeOfAnimals t);
};

class Animal {
 private:
  int time_ = 0;  // время жизни
 public:
  virtual void Feed();
  virtual void Sell();
  virtual void GiveResources(int k);
  virtual void Die();
  virtual ~Animal() = default;
};

class Pig : public Animal {};

class Hen : public Animal {};

class Cow : public Animal {};
