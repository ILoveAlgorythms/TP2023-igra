#include <vector>
#include <unordered_map>
#include <string>
#include "player.hpp"
#include "animal.hpp"

enum TypeOfBuildings { Bathhouse, House };

struct Base {
 private:
  Player p_;
  std::unordered_map<std::string,TypeOfAnimals>Pets_;
  std::unordered_map<std::string,TypeOfBuildings>Buildings_;

 public:
  int test = 0;
  Base();
  ~Base() = default;
  void Build(std::string s, TypeOfBuildings t); // убрал, потому что мб мы захотим чето ещё делать когда появляется новое здание
  void GetAnimal(std::string s, TypeOfAnimals t);
  void RemoveAnimal(std::string s);
  void RemoveBuilding(std::string s);
};
