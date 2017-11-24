#include "Zork.h"
#include "Item.h"
#include <iostream>

using namespace std;
using namespace rapidxml;

int main(int argc, char** argv) {
  Zork zork;
  zork.initializeGame(argv[1]);

  xml_document<>* xml_doc = zork.getXMLDocument();
  xml_node<>* map_node = NULL;
  xml_node<>* list_node = NULL;

  vector<Item> itemlist;

  if(xml_doc->first_node() != NULL) {
    map_node = xml_doc->first_node();
  }

  if(map_node->first_node("item") != NULL) {
    list_node = map_node->first_node("item");
    itemlist.push_back(Item(list_node));

    while(list_node->next_sibling("item") != NULL) {
      list_node = list_node->next_sibling();
      itemlist.push_back(Item(list_node));
    }
  }

  cout << "itemlist.size() = " << itemlist.size() << endl;

  for(int i = 0; i < itemlist.size(); i++) {
    cout << "Item " << i << endl;
    cout << itemlist[i].getName() << endl;
    cout << itemlist[i].getWriting() << endl;
    cout << itemlist[i].getStatus() << endl;
    cout << itemlist[i].getTurnonPrint() << endl;
    cout << itemlist[i].getTurnonAction() << endl;
    cout << endl;
  }

  return 0;
}
