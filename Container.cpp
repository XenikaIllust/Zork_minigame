#include "Container.h"
#include <iostream>

using namespace std;
using namespace rapidxml;

Container::Container(xml_node<>* newContainer) : trigger( (newContainer != nullptr && newContainer->first_node("trigger") == nullptr) ? newContainer->first_node("trigger") : nullptr) {
  if(newContainer != nullptr) {
    if(newContainer->first_node("name") != nullptr)
      this->name = newContainer->first_node("name")->value();
    else
      this->name = "";
    
    if(newContainer->first_node("status") != nullptr) 
      this->status = newContainer->first_node("status")->value();
    else
      this->status = "";
    
    if(newContainer->first_node("accept") != nullptr)
      this->accept = newContainer->first_node("accept")->value();
    else
      this->accept = "";

    if(newContainer->first_node("item") != nullptr) {
      xml_node<>* list_node = newContainer->first_node("item");
      itemlist.push_back(list_node->value());

      while(list_node->next_sibling("item") != nullptr) {
	list_node = list_node->next_sibling();
	itemlist.push_back(list_node->value());
      }
    }
  }
}

string Container::getName() {
  return this->name;
}

string Container::getStatus() {
  return this->status;
}

string Container::getAccept() {
  return this->accept;
}

string Container::getItem(int i) {
  return this->itemlist[i];
}

int Container::getItemlistSize() {
  return this->itemlist.size();
}

Container::~Container(){

}
