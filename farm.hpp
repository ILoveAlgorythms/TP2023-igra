#include <vector>
#include <unordered_map>
#include <string>
#include "animal.hpp"

enum TypeOfBuildings { Bathhouse, House };

struct Base {
 private:
  std::unordered_map<std::string, Animal*>Pets_; 
  // #warning "я поменял TypeOfAnimals на Animal*, скажи если я чего-то не понял и там нужно хранить именно тип а не ссылку на весь класс (ссылку он не хочет создавать чето)
  std::unordered_map<std::string, TypeOfBuildings>Buildings_;

 public:
  int test = 0;
  Base();
  ~Base() = default;
  void Build(std::string s, TypeOfBuildings t); // убрал, потому что мб мы захотим чето ещё делать когда появляется новое здание
  void GetAnimal(std::string s, Animal* t);
  void RemoveAnimal(std::string s);
  void RemoveBuilding(std::string s);
};
