#ifndef TRIGGER_H
#define TRIGGER_H
#include "Condition.h"
#include <string>
#include <vector>
#include "rapidxml-1.13/rapidxml.hpp"
#include "rapidxml-1.13/rapidxml_print.hpp"

class Trigger{
public:  
  Trigger(rapidxml::xml_node<>*);
  virtual ~Trigger();
  
  std::string getType();
  std::string getCommand();
  std::string getAction(int i);
  int getActionSize();
  std::string getPrint();
  bool getTriggerStatus();

  Condition condition;
  
private:
  std::string type;
  std::string command;
  std::vector<std::string> action;
  std::string print;
  bool isTriggered;
};

#endif
