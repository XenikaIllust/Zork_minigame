#include "Creature.h"
#include <iostream>

using namespace std;
using namespace rapidxml;

Attack::Attack(xml_node<>* newAttack) : condition( newAttack != nullptr && newAttack->first_node("condition") != nullptr ? newAttack->first_node("condition") : nullptr)
{
    if(newAttack != nullptr) {
      if(newAttack->first_node("action") != nullptr) {
	xml_node<>* action_node = newAttack->first_node("action");
        this->actionlist.push_back(action_node->value());
	
	while(action_node->next_sibling("action") != nullptr) {
	  action_node = action_node->next_sibling("action");
	  this->actionlist.push_back(action_node->value());
	}
      }
      
      if(newAttack->first_node("print") != nullptr) {
	xml_node<>* print_node = newAttack->first_node("print");
        this->printlist.push_back(print_node->value());
	
	while(print_node->next_sibling("print") != nullptr) {
	  print_node = print_node->next_sibling("print");
	  this->printlist.push_back(print_node->value());
	}
      }
    }
}

Attack::~Attack() {}

Creature::Creature(xml_node<>* newCreature) : trigger( newCreature != nullptr && newCreature->first_node("trigger") != nullptr ? newCreature->first_node("trigger") : nullptr ), attack( newCreature != nullptr && newCreature->first_node("attack") != nullptr ? newCreature->first_node("attack") : nullptr ) {
  if(newCreature != nullptr) {
    if(newCreature->first_node("name") != nullptr)
      this->name = newCreature->first_node("name")->value();
    else
      this->name = "";

    if(newCreature->first_node("vulnerability") != nullptr) {
      xml_node<>* list_node = newCreature->first_node("vulnerability");
      vulnerabilitylist.push_back(list_node->value());

      while(list_node->next_sibling("vulnerability") != nullptr) {
	list_node = list_node->next_sibling("vulnerability");
        this->vulnerabilitylist.push_back(list_node->value());
      }
    }
  }
}

string Creature::getName() {
  return this->name;
}

string Creature::getVulnerability(int i) {
  return this->vulnerabilitylist[i];
}

int Creature::getVulnerabilitylistSize() {
  return this->vulnerabilitylist.size();
}

Creature::~Creature(){

}
