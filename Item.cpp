#include "Item.h"
#include <iostream>

using namespace std;
using namespace rapidxml;

Item::Item(xml_node<>* newItem){
  this->name = newItem->first_node("name")->value();

  if(newItem->first_node("writing") != nullptr) 
    this->writing = newItem->first_node("writing")->value();
  else
    this->writing = "";

  if(newItem->first_node("status") != nullptr) 
    this->status = newItem->first_node("status")->value();
  else
    this->status = "";

  xml_node<>* turnon_node = nullptr;
  
  if(newItem->first_node("turnon") != nullptr) {
    turnon_node = newItem->first_node("turnon");

    if(turnon_node->first_node("print") != nullptr)
      TurnOn.print = turnon_node->first_node("print")->value();
    else
      TurnOn.print = "";

    if(turnon_node->first_node("action") != nullptr)
      TurnOn.action = turnon_node->first_node("action")->value();
    else
      TurnOn.action = "";
  }
}

string Item::getName() {
  return this->name;
}

string Item::getWriting() {
  return this->writing;
}

string Item::getStatus() {
  return this->status;
}

string Item::getTurnonPrint() {
  return TurnOn.print;
}

string Item::getTurnonAction() {
  return TurnOn.action;
  }

/*void Item::Item(string newItem, string newWriting){
	name = newItem;
	setWriting(newWriting);
}

void Item::Item(string newItem, string newWriting, string newStatus){
	name = newItem;
	setWriting(newWriting);
	setStatus(newStatus);
}

void Item::setWriting(string newWriting){
	writing = newWrting;
}

void Item::setStatus(string newStatus){
	status = newStatus;
}

void Item::setIsOn(string newPrint, string, newAction){
	isOn.print = newPrint;
	isOn.action = newAction;
}*/

Item::~Item(){

}
