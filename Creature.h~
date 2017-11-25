#ifndef ITEM_H
#define ITEM_H
#include <string>
#include "rapidxml-1.13/rapidxml.hpp"
#include "rapidxml-1.13/rapidxml_print.hpp"

typedef struct {
  std::string print;
  std::string action;
} turnon;

class Item{
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
  std::string writing;
  std::string status;
  turnon TurnOn;
};

#endif
