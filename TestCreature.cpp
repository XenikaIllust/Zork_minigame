//ONLY TEST CREATURESAMPLE.XML OR SAMPLETXT.XML

#include "Zork.h"
#include "Creature.h"
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

  vector<Creature> creaturelist;
  
  if(map_node->first_node("creature") != NULL) {
    xml_node<>* list_node = map_node->first_node("creature");
    Creature creature(list_node);
    creaturelist.push_back(creature);
    
    while(list_node->next_sibling("creature") != NULL) {
      list_node = list_node->next_sibling();
      Creature creature(list_node);
      creaturelist.push_back(creature);
    }
  }

  for(int i = 0; i < creaturelist.size(); i++) {
    cout << "Creature " << i << endl;
    cout << creaturelist[i].getName() << endl;

    for(int j = 0; j < creaturelist[i].getVulnerabilitylistSize(); j++) 
      cout << "Vulnerability " << j << " " << creaturelist[i].getVulnerability(j);

    for(int k = 0; k < creaturelist[i].attack.actionlist.size(); k++)
      cout << creaturelist[i].attack.actionlist[k] << endl;

    for(int k = 0; k < creaturelist[i].attack.printlist.size(); k++)
      cout << creaturelist[i].attack.printlist[k] << endl;

    cout << endl;
  }

  return 0;
}
