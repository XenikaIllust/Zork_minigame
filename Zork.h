#ifndef ZORK_H
#define ZORK_H
#include "rapidxml-1.13/rapidxml.hpp"
#include "rapidxml-1.13/rapidxml_print.hpp"
#include <vector>
#include <string>

class Zork {
public:
  Zork();
  virtual ~Zork();
  void initializeGame(std::string filepath);
  rapidxml::xml_document<>* getXMLDocument();
  
private:
  std::vector<char> xml_copy;
  rapidxml::xml_document<> doc;
};

#endif
