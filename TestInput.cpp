#include <string>
#include "Input.h"
#include "rapidxml-1.13/rapidxml.hpp"

using namespace std;
using namespace rapidxml;

int main() {
  Input input;
  
  while (true) {
    cout << "Type input here :" << endl;
    input.getInput();
    
    cout << "direction: " << input.getDirection() << endl;
    cout << "command: " << input.getCommand() << endl;
    cout << "creature: " << input.getCreature() << endl;
    cout << "item: " << input.getItem() << endl;
    cout << "container: " << input.getContainer() << endl;
  }
  
  return 0;
}
