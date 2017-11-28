//ONLY TEST ROOMSAMPLE.XML OR SAMPLETXT.XML

#include "Zork.h"
#include "Room.h"
#include <iostream> 

using namespace std;
using namespace rapidxml;

int main(int argc, char** argv) {
  Zork zork;
  zork.initializeGame(argv[1]);

  xml_document<>* xml_doc = zork.getXMLDocument();
  xml_node<>* map_node = nullptr;

  if(xml_doc->first_node() != nullptr) {
    map_node = xml_doc->first_node();
  }

  vector<Room> roomlist;
  
  if(map_node->first_node("room") != NULL) {
    xml_node<>* list_node = map_node->first_node("room");
    Room room(list_node);
    roomlist.push_back(room);
    
    while(list_node->next_sibling("room") != NULL) {
      list_node = list_node->next_sibling();
      Room room(list_node);
      roomlist.push_back(room);
    }
  }

  return 0;
}
