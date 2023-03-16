#include <algorithm>
#include <iostream>
#include <vector>

enum type_of_player{
  woodworker,
  tradesman,
  herdsman
};

enum type_of_animals{
  hen,
  cow,
  pig
};

enum type_of_buildings{
  bathhouse,
  house
};

class resources {
private:
  int money = 0;
  int eggs = 0;
  int meat = 0;
  int milk = 0;
public:
  resources() = default;
  ~resources() = default;
  resources& operator=(const resources& r1) = default;
  resources(int k) : money(k), eggs(0), meat(0), milk(0) {}

  void pay_money(int x) {}
  void give_eggs(int x) {}
  void give_meat(int x) {}
  void give_milk(int x) {}
  void get_milk(int x) { milk += x; }
  void get_eggs(int x) { eggs += x; }
  void get_money(int x) { money += x; }
  void get_meat(int x) { meat += x; }
};

class player {
private:
  resources r;
  type_of_player type = woodworker;
};

struct base {
private:
  player p;
  std::vector<type_of_animals> pets;
  std::vector<type_of_buildings> buildings;
public:
  base() = default;
  ~base() = default;
  void build(type_of_buildings t) {
    buildings.push_back(t);
  }
  void get_animal(type_of_animals t) {
    pets.push_back(t);
  }
};

class animal {
private:
  int time = 0; //время жизни
public:
  virtual void feed();
  virtual void sell();
  virtual void give_resources(int k);
  virtual void die();
  virtual ~animal() = default;
};

class pig : public animal {
  void feed() override {}
  void sell() override {}
  void give_resources(int k) override {}
  void die() override {}
};

class hen : public animal {
  void feed() override {}
  void sell() override {}
  void give_resources(int k) override {}
  void die() override {}
};

class cow : public animal {
  void feed() override {}
  void sell() override {}
  void give_resources(int k) override {}
  void die() override {}
};


