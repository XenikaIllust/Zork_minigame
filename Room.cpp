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

    if(newRoom->first_node("border") != nullptr) {
      xml_node<>* border_node = newRoom->first_node("border");
      this->setBorder(border_node);
    }
  }
}

Room::~Room() {}

string Room::getRoomName(){
  return this->name;
}

string Room::getRoomDesciption(){
  return this->description;
}

string Room::getRoomType(){
  return this->type;
}
