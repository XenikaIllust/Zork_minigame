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

  for(int i = 0; i < roomlist.size(); i++) {
    cout << "Room " << i << endl;
    cout << roomlist[i].getName() << endl;
    cout << roomlist[i].getDescription() << endl;
    cout << roomlist[i].getType() << endl;

    for(int j = 0; j < roomlist[i].getItemlistSize(); j++) {
      cout << roomlist[i].getItem(j) << endl;
    }

    for(int j = 0; j < roomlist[i].getContainerlistSize(); j++) {
      cout << roomlist[i].getContainer(j) << endl;
    }

    for(int j = 0; j < roomlist[i].getCreaturelistSize(); j++) {
      cout << roomlist[i].getCreature(j) << endl;
    }

    cout << endl;
  }

  return 0;
}
