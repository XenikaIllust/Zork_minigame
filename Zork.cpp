#include "Zork.h"
#include <fstream>
#include <iostream>

using namespace std;
using namespace rapidxml;

Zork::Zork() {
}

void Zork::initializeGame(string filepath) {
  string input_xml;
  string line;

  ifstream in(filepath);
  
  if(!(in.is_open())){
    cout << "Cannot open file!" << endl;
    //Set game over status to 1
    return;
  }
  
  while(getline(in, line))
    input_xml += line;

  for(int i = 0; i < input_xml.length(); i++) {
    this->xml_copy.push_back(input_xml[i]);
  }

  this->doc.parse<0>(&this->xml_copy[0]);
  in.close();
  return;
}

xml_document<>* Zork::getXMLDocument() {
  xml_document<>* docptr = &(this->doc);
  return docptr;
}

Zork::~Zork() {}

