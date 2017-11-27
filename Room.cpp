#include "Room.h"

Room::Room(xml_node<>* newRoom){
  if(newRoom != nullptr) {
    if(newRoom->first_node("name") != nullptr)
      this->name = newRoom->first_node("name")->value();
    else
      this->name = "";

    if(newRoom->first_node("description") != nullptr) 
      this->description = roomDescription;
    else
      this->description = "";

    if(newRoom->first_node("border") != nullptr) {
      xml_node<>* border_node = newRoom->first_node("border");
      this->setBorder(border_node);
    }
  }
}

void Room::setType(string newType){
  type = newType;
  return;
}

string Room::getRoomName(){
  return this->name;
}

string Room::getRoomDesciption(){
  return this->description;
}

string Room::getType(){
  return this->type;
}
