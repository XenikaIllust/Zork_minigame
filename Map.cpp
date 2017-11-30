#include "Map.h"

using namespace std;
using namespace rapidxml;

Map::Map(xml_node<>* newMap) {
    if(newMap->first_node("room") != nullptr) {
      xml_node<>* room_node = newMap->first_node("room");
      Room room(room_node);
      this->roomlist.push_back(room);

      while(room_node->next_sibling("room") != nullptr) {
	room_node = room_node->next_sibling("room");
	Room room(room_node);
	this->roomlist.push_back(room);
      }
    }

    if(newMap->first_node("item") != nullptr) {
      xml_node<>* item_node = newMap->first_node("item");
      this->itemlist.push_back(item_node);

      while(item_node->next_sibling("item") != nullptr) {
        item_node = item_node->next_sibling("item");
	this->itemlist.push_back(item_node);
      }
    }

    if(newMap->first_node("container") != nullptr) {
      xml_node<>* container_node = newMap->first_node("container");
      this->containerlist.push_back(container_node);

      while(container_node->next_sibling("container") != nullptr) {
        container_node = container_node->next_sibling("container");
	this->containerlist.push_back(container_node);
      }
    }

    if(newMap->first_node("creature") != nullptr) {
      xml_node<>* creature_node = newMap->first_node("creature");
      this->creaturelist.push_back(creature_node);

      while(creature_node->next_sibling("creature") != nullptr) {
        creature_node = creature_node->next_sibling("creature");
	this->creaturelist.push_back(creature_node);
      }
    }
}


Map::~Map() {}

Room* Map::getRoom(int i){
  return &(this->roomlist[i]);
}

int Map::getRoomlistSize(){
  return this->roomlist.size();
}

Item Map::getItem(int i){
  return this->itemlist[i];
}

int Map::getItemlistSize(){
  return this->itemlist.size();
}

Container* Map::getContainer(int i){
  return &(this->containerlist[i]);
}

int Map::getContainerlistSize(){
  return this->containerlist.size();
}

Creature Map::getCreature(int i){
  return this->creaturelist[i];
}

int Map::getCreaturelistSize(){
  return this->creaturelist.size();
}
