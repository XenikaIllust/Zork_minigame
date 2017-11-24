#include "XMLParser.h"
#include <string>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "rapidxml-1.13/rapidxml.hpp"
#include "rapidxml-1.13/rapidxml_print.hpp"

using namespace std;
using namespace rapidxml;

void XMLParser::initParser(string filepath) {
	//Initialize the XMLParsing files

	string line;
	string input_xml;
	ifstream in(filepath);

	if (!(in.is_open())) {
		cout << "File open error." << endl;
		return;
	}

	while (getline(in, line))
		input_xml += line;

	for (int i = 0; i < input_xml.length(); i++)
		this->xml_copy.push_back(input_xml[i]);
}
/*
	this->xml_copy.push_back('\0');
	this->xml_doc.parse<0>(&(this->xml_copy[0]));
	return;
}

void XMLParser::retrieveXMLElement(xml_node<> *location, string name) { 
	//retrieves the relevant element in this location

	this->xml_content = location->first_node(name.c_str());
	return;
}*/

