#include "Zork.h"
#include "Map.h"
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
  
  Map map(map_node);

  for(int i = 0; i < map.getRoomlistSize(); i++) {
    cout << "Room " << i << endl;
    cout << map.getRoom(i).getName() << endl;
    cout << endl;
  }

  for(int i = 0; i < map.getItemlistSize(); i++) {
    cout << "Item " << i << endl;
    cout << map.getItem(i).getName() << endl;
    cout << endl;
  }

  for(int i = 0; i < map.getContainerlistSize(); i++) {
    cout << "Container " << i << endl;
    cout << map.getContainer(i).getName() << endl;
    cout << endl;
  }

  for(int i = 0; i < map.getCreaturelistSize(); i++) {
    cout << "Creature " << i << endl;
    cout << map.getCreature(i).getName() << endl;
    cout << endl;
  }

  return 0;
}
