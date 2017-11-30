#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include <vector>

class Inventory{
public:  
  std::string getItem(int i);
  int getItemlistSize();
  void addItem(std::string item);
  void removeItem(std::string item);
  void printInventory();
  
private:
  std::vector<std::string> itemlist;
};

class Player{
public:
  Inventory* getInventory();

private:
  std::string name;
  std::string status;
  Inventory inventory;
};

#endif
