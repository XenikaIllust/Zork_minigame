#ifndef CONTAINER_H
#define CONTAINER_H
#include <string>
#include "rapidxml-1.13/rapidxml.hpp"
#include "rapidxml-1.13/rapidxml_print.hpp"
#include "Trigger.h"

class Container{
public:  
  Container(rapidxml::xml_node<>*);
  virtual ~Container();
  
  std::string getName();
  std::string getStatus();
  std::string getAccept();
  std::string getItem(int i);
  int getItemlistSize();
  bool getOpenStatus();
  void changeOpenStatus(bool status);
  void addItem(std::string item);
  void removeItem(std::string item);
  
  Trigger trigger;
  
private:
  std::string name;
  std::string status;
  std::string accept;
  std::vector<std::string> itemlist;
  bool openStatus;
};

#endif
