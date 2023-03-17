#include <vector>
#include "player.hpp"
#include "animal.hpp"

enum TypeOfBuildings { Bathhouse, House };

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
