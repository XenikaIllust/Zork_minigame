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
  //void Item(string, string);
  //void Item(string, string, string);
  virtual ~Item();
  
  //void setWriting(string);
  //void setStatus(string);
  //void setIsOn(string, string);
  
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
