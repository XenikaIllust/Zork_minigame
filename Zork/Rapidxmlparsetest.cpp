#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "rapidxml-1.13/rapidxml.hpp"

using namespace std;
using namespace rapidxml;

int main()
{
	string input_xml;
	string line;
	ifstream in("sampletxt.xml");

	while (getline(in, line))
		input_xml += line;

	vector<char> xml_copy(input_xml.begin(), input_xml.end());
	xml_copy.push_back('\0');

	xml_document<> doc;
	doc.parse<parse_declaration_node | parse_no_data_nodes>(&xml_copy[0]);

	xml_node<>* cur_node = doc.first_node("map");
	
	xml_attribute<>* attr = cur_node->first_attribute();

	cout << attr->name() << endl;
}


