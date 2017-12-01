#ifndef CREATURE_H
#define CREATURE_H
#include <string>
#include <vector>
#include "rapidxml-1.13/rapidxml.hpp"
#include "rapidxml-1.13/rapidxml_print.hpp"
#include "Trigger.h"
#include "Condition.h"

class Attack {
public:
  Attack(rapidxml::xml_node<>*);
  virtual ~Attack();

  std::string getPrint(int i);
  int getPrintlistSize();
  std::string getAction(int i);
  int getActionlistSize();
  
  std::vector<std::string> actionlist;
  std::vector<std::string> printlist;
  Condition condition;
};

class Creature{
public:  
  Creature(rapidxml::xml_node<>*);
  virtual ~Creature();
  
  std::string getName();
  std::string getVulnerability(int i);
  int getVulnerabilitylistSize();
  Attack getAttack();
  bool getDeathStatus();

  Trigger trigger;
  Attack attack;
  
private:
  std::string name;
  std::vector<std::string> vulnerabilitylist;
  bool isDead;
};

#endif
