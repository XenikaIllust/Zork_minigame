#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include "rapidxml-1.13/rapidxml.hpp"
#include "rapidxml-1.13/rapidxml_print.hpp"
#include "Trigger.h"

class Inventory{
public:  
  Inventory();
  virtual ~Inventory();
  
  std::string getName();
  std::string getStatus();
  std::string getAccept();
  std::string getItem(int i);
  int getItemlistSize();
  
  Trigger trigger;
  
private:
  std::string name;
  std::string status;
  std::string accept;
  std::vector<std::string> itemlist;
};

#endif
