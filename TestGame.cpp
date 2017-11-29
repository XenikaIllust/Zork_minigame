#include "Zork.h"
#include "GameEngine.h"
#include "Map.h"
#include <iostream> 

using namespace std;
using namespace rapidxml;

int main(int argc, char** argv) {
  Zork zork;
  zork.initializeGame(argv[1]);

  xml_document<>* xml_doc = zork.getXMLDocument();
  xml_node<>* map_node = nullptr;

  if(xml_doc->first_node() != nullptr) 
    map_node = xml_doc->first_node();
  else {
    cout << "Error running game" << endl;
    return 0;
  }
    
  cout << "Welcome to Zork, a land of fantasy awaits..." << endl;
  
  Map map(map_node);
  RunGame(&map);

  cout << "Game over!" << endl;

  return 0;
}
