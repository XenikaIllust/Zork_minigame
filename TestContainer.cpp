//ONLY TEST CONTAINERSAMPLE.XML OR SAMPLETXT.XML

#include "Zork.h"
#include "Container.h"
#include <iostream>
#include <vector>

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
  
  vector<Container> containerlist;
  
  if(map_node->first_node("container") != NULL) {
    xml_node<>* list_node = map_node->first_node("container");
    Container container(list_node);
    containerlist.push_back(container);
    
    while(list_node->next_sibling("container") != NULL) {
      list_node = list_node->next_sibling();
      Container container(list_node);
      containerlist.push_back(container);
    }
  }

  for(int i = 0; i < containerlist.size(); i++) {
    cout << "Container " << i << endl;
    cout << containerlist[i].getName() << endl;
    cout << containerlist[i].getStatus() << endl;
    cout << containerlist[i].getAccept() << endl;

    for(int j = 0; j < containerlist[i].getItemlistSize(); j++) 
      cout << "Item " << j << " " << containerlist[i].getItem(j);
    
    cout << containerlist[i].trigger.getType() << endl;
    cout << containerlist[i].trigger.getCommand() << endl;

    for(int k = 0; k < containerlist[i].trigger.getActionSize(); k++)
      cout << containerlist[i].trigger.getAction(k) << endl;
    
    cout << containerlist[i].trigger.getPrint() << endl;

    cout << endl;
  }

  return 0;
}
