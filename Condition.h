#ifndef CONDITION_H
#define CONDITION_H
#include <string>
#include "rapidxml-1.13/rapidxml.hpp"
#include "rapidxml-1.13/rapidxml_print.hpp"

class Condition{
public:  
  Condition(rapidxml::xml_node<>*);
  virtual ~Condition();
  
  std::string getObject();
  std::string getStatus();
  std::string getOwner();
  std::string getHas();
  
private:
  std::string object;
  std::string status;
  std::string owner;
  std::string has;
};

#endif
