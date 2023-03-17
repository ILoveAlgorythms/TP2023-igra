#include "resources.hpp"
#pragma once

enum TypeOfPlayer { Woodworker, Tradesman, Herdsman };

class Player {
 private:
  Resources r_;
  TypeOfPlayer type_ = Woodworker;
};