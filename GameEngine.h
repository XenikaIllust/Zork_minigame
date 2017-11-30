#include "Input.h"
#include "Player.h"
#include "Map.h"

void RunGame(Map* map_ptr);

class GameEngine {
public:
  void Error();
  void Operation(Map* map_ptr, Input input, Player* player_ptr, std::string* autoInputstr, int* currentRoom, int* gameOverStatusPtr);
  
private:
  std::string direction;
};
