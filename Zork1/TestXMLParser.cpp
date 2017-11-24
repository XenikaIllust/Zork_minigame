#include "XMLParser.h"
#include <iostream>
#include <string>

using namespace std;

int main() {
	XMLParser XMLparser;
	XMLparser.initParser("roomsample.xml");
	//XMLparser.retrieveXMLElement(XMLparser.xml_doc.first_node(),"room");
	return 0;
}