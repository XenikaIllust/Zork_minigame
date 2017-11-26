#ifndef CONTAINER_H
#define CONTAINER_H
#include <string>
#include "rapidxml-1.13/rapidxml.hpp"
#include "rapidxml-1.13/rapidxml_print.hpp"
#include "Item.h"

class Container{
public:  
  Item(rapidxml::xml_node<>*);
  virtual ~Item();
  
  std::string getName();
  std::string getWriting();
  std::string getStatus();
  std::string getTurnonPrint();
  std::string getTurnonAction();
  
private:
  std::string name;
  Item item;
  std::string status;
};

#endif
