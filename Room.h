#ifndef ROOM_H
#define ROOM_H

#include <iostream>
#include <vector>
#include <string>
#include "rapidxml-1.13/rapidxml.hpp"
#include "rapidxml-1.13/rapidxml_print.hpp"
#include "Trigger.h"
#include "Border.h"

class Room {
public:
  Room(rapidxml::xml_node<>*);
  virtual ~Room();
  
  std::string getName();
  std::string getDescription();
  std::string getType();
  Border getBorder(int i);
  int getBorderlistSize();
  std::string getItem(int i);
  int getItemlistSize();
  void addItem(std::string);
  void removeItem(std::string);
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
