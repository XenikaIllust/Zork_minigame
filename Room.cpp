#include "Room.h"

using namespace std;
using namespace rapidxml;

Room::Room(xml_node<>* newRoom) : trigger( newRoom != nullptr && newRoom->first_node("trigger") != nullptr ? newRoom->first_node("trigger") : nullptr) {
  if(newRoom != nullptr) {
    if(newRoom->first_node("name") != nullptr)
      this->name = newRoom->first_node("name")->value();
    else
      this->name = "";

    if(newRoom->first_node("description") != nullptr) 
      this->description = newRoom->first_node("description")->value();
    else
      this->description = "";

    if(newRoom->first_node("type") != nullptr) 
      this->type = newRoom->first_node("type")->value();
    else
      this->type = "";

    if(newRoom->first_node("border") != nullptr) {
      xml_node<>* border_node = newRoom->first_node("border");
      Border border(border_node);
      this->borderlist.push_back(border);

      while(border_node->next_sibling("border") != nullptr) {
	border_node = border_node->next_sibling("border");
	Border border(border_node);
	this->borderlist.push_back(border);
      }
    }

    if(newRoom->first_node("item") != nullptr) {
      xml_node<>* item_node = newRoom->first_node("item");
      this->itemlist.push_back(item_node->value());

      while(item_node->next_sibling("item") != nullptr) {
        item_node = item_node->next_sibling("item");
	this->itemlist.push_back(item_node->value());
      }
    }

    if(newRoom->first_node("container") != nullptr) {
      xml_node<>* container_node = newRoom->first_node("container");
      this->containerlist.push_back(container_node->value());

      while(container_node->next_sibling("container") != nullptr) {
        container_node = container_node->next_sibling("container");
	this->containerlist.push_back(container_node->value());
      }
    }

    if(newRoom->first_node("creature") != nullptr) {
      xml_node<>* creature_node = newRoom->first_node("creature");
      this->creaturelist.push_back(creature_node->value());

      while(creature_node->next_sibling("creature") != nullptr) {
        creature_node = creature_node->next_sibling("creature");
	this->creaturelist.push_back(creature_node->value());
      }
    }
  }
}

Room::~Room() {}

string Room::getName(){
  return this->name;
}

string Room::getDescription(){
  return this->description;
}

string Room::getType(){
  return this->type;
}

Border Room::getBorder(int i){
  return this->borderlist[i];
}

int Room::getBorderlistSize(){
  return this->borderlist.size();
}

string Room::getItem(int i){
  return this->itemlist[i];
}

int Room::getItemlistSize(){
  return this->itemlist.size();
}

void Room::addItem(string item) {
  this->itemlist.push_back(item);
}

void Room::removeItem(string item) {
  for(int i = 0; i < itemlist.size(); i++) {
    if(itemlist[i] == item) 
      this->itemlist.erase(itemlist.begin() + i);
  }
}

string Room::getContainer(int i){
  return this->containerlist[i];
}

int Room::getContainerlistSize(){
  return this->containerlist.size();
}

string Room::getCreature(int i){
  return this->creaturelist[i];
}

int Room::getCreaturelistSize(){
  return this->creaturelist.size();
}

void Room::addCreature(string creature) {
  this->creaturelist.push_back(creature);
}

void Room::removeCreature(string creature) {
  for(int i = 0; i < creaturelist.size(); i++) {
    if(creaturelist[i] == creature) 
      this->creaturelist.erase(creaturelist.begin() + i);
  }
}


