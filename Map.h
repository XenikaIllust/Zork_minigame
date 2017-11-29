#ifndef MAP_H
#define MAP_H

#include <string>
#include <vector>
#include "rapidxml-1.13/rapidxml.hpp"
#include "rapidxml-1.13/rapidxml_print.hpp"
#include "Room.h"
#include "Item.h"
#include "Container.h"
#include "Creature.h"

class Map {
public:
  Map(rapidxml::xml_node<>*);
  virtual ~Map();

  Room getRoom(int i);
  int getRoomlistSize();
  Item getItem(int i);
  int getItemlistSize();
  Container getContainer(int i);
  int getContainerlistSize();
  Creature getCreature(int i);
  int getCreaturelistSize();

private:
  std::vector<Room> roomlist;
  std::vector<Item> itemlist;
  std::vector<Container> containerlist;
  std::vector<Creature> creaturelist;
};

#endif
