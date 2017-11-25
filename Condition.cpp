#include "Condition.h"
#include <iostream>

using namespace std;
using namespace rapidxml;

Condition::Condition(xml_node<>* newCondition){
  if(newCondition != NULL) {
    if(newCondition->first_node("object") != nullptr)
      this->object = newCondition->first_node("object")->value();
    else
      this->object = "";
    
    if(newCondition->first_node("status") != nullptr) 
      this->status = newCondition->first_node("status")->value();
    else
      this->status = "";
    
    if(newCondition->first_node("owner") != nullptr) 
      this->owner = newCondition->first_node("owner")->value();
    else
      this->owner = "";

    if(newCondition->first_node("has") != nullptr) 
      this->has = newCondition->first_node("has")->value();
    else
      this->has = "";
  }
}

string Condition::getObject() {
  return this->object;
}

string Condition::getStatus() {
  return this->status;
}

string Condition::getOwner() {
  return this->owner;
}

string Condition::getHas() {
  return this->has;
  }

Condition::~Condition(){

}
