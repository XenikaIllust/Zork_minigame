#ifndef ROOM_H
#define ROOM_H

#include "Border.h"
#include <iostream>
#include <vector>
#include <string>
#include "rapidxml-1.13/rapidxml.hpp"
#include "rapidxml-1.13/rapidxml_print.hpp"
#include "Trigger.h"

class Room {
public:
  Room(rapidxml::xml_node<>*);
  virtual ~Room();
  std::string getRoomName();
  std::string getRoomDescription();
  std::string getRoomType();
  std::string getItem(int i);
  int getItemlistSize();
  std::string getContainer(int i);
  int getContainerlistSize();
  std::string getCreature(int i);
  int getCreaturelistSize();

private:
  std::string name;
  std::string description;
  std::string type;
  std::vector<Border> borderlist;
  std::vector<std::string> itemlist;
  std::vector<std::string> containerlist;
  std::vector<std::string> creaturelist;
  Trigger trigger;
};

#endif
