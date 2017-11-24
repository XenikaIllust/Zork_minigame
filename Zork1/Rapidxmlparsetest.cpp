#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "rapidxml-1.13/rapidxml.hpp"
#include "rapidxml-1.13/rapidxml_print.hpp"

using namespace std;
using namespace rapidxml;

int main()
{
	string input_xml;
	string line;
	ifstream in("SamplePack/sampletxt.xml");

	while (getline(in, line))
		input_xml += line;

	vector<char> xml_copy(input_xml.begin(), input_xml.end());
	xml_copy.push_back('\0');

	xml_document<> doc;
	doc.parse<0>(&xml_copy[0]);

	cout << doc << endl;

	xml_node<> *map_node = doc.first_node();
	cout << "Name of map node is: " << map_node->name() << "\n";
	xml_node<> *room_node = map_node->first_node();
	cout << "Name of room node is: " << room_node->name() << endl;
	xml_node<> *name_node = room_node->first_node("name");
	cout << "Value of name node is: " << name_node->value() << endl;
	xml_node<> *sibling_node = name_node->next_sibling();
	cout << "Value of sibling node is: " << sibling_node->value() << endl;
	xml_node<> *sibling_node2 = sibling_node->next_sibling();
	cout << "Value of sibling2 node is: " << sibling_node->next_sibling()->value() << endl;
	xml_node<> *sibling_node2child = sibling_node2->first_node();
	cout << "Value of sibling_node2child is: " << sibling_node2child->value() << endl;
}


