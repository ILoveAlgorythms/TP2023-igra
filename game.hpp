#include "button.hpp"

class Game { // singleton
public: 
    Map& GetMap() {
      return *map_;
    }

    std::vector<std::vector<bool>>& GetFlags() {
      return flags_map_;
    }

    int CheckStatus() {
      return status_;
    }

    static Game* GetGame() {
      if (game_ == nullptr) {
        game_ = new Game(20, 50);
      }
      return game_;
    }

    ~Game() {
      delete map_;
    }
  private:
    static Game* game_;

    Game(size_t size, size_t mines) 
      : flags_map_(size, std::vector<bool>(size, false)) {
      map_ = MapBuilder(size).GenerateCells()->GenerateMines(mines)->Build();
    }

    std::vector<std::vector<bool>> flags_map_;
    int status_{proccess};
    Map* map_;
};

Game* Game::game_{nullptr};
