#include "Border.h"

using namespace std;
using namespace rapidxml;

Border::Border(xml_node<>* newBorder){
  if(newBorder != nullptr) {
    if(newBorder->first_node("name") != nullptr)
      this->name = newBorder->first_node("name")->value();
    else
      name = "";

    if(newBorder->first_node("direction") != nullptr)
      this->direction = newBorder->first_node("direction")->value();
    else
      name = "";
  }
}

string Border::getDirection(){
	return this->direction;
}

string Border::getName(){
	return this->name;
}

Border::~Border() {
}
