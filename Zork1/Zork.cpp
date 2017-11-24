#include "Zork.h"
#include <fstream>

Zork::Zork(string filepath) {
  string input_xml;
  string line;
  ifstream in(filepath);

  while(getline(in, line))
    input_xml += line;

  for(i = 0; i < input_xml.length(); i++) {
    this->xml_copy.push_back(input_xml[i]);
  }

  this->doc.parse<0>(&this->xml_copy[0]);
}

Zork::~Zork() {}

