#ifndef XMLPARSER
#define XMLPARSER

#include <string>
#include <vector>
#include "rapidxml-1.13/rapidxml.hpp"
#include "rapidxml-1.13/rapidxml_print.hpp"

class XMLParser {
public:
	void initParser(std::string filepath);
	//void retrieveXMLElement(rapidxml::xml_node<> *location, std::string name);
	rapidxml::xml_document<> xml_doc;

private:
	std::vector<char> xml_copy;
	rapidxml::xml_node<> *xml_content;
};

#endif // !XMLPARSER