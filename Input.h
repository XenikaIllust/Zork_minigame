#ifndef INPUT_H
#define INPUT_H

#include <iostream>
#include <string>
#include <vector>

class Input {
public:
  void getInput(std::string* autoInputstr);
  void error();
  
  std::string getDirection();
  std::string getCommand();
  std::string getContainer();
  std::string getItem();
  std::string getCreature();
  std::string getRoom();
  
private:
  std::vector<std::string> input;
  std::string command;
  std::string direction;
  std::string item;
  std::string creature;
  std::string container;
  std::string room;
};

#endif
