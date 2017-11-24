#include "Zork.h"
#include <iostream>

using namespace std;

int main(int argc, char** argv) {

  Zork zork;

  zork.initializeGame(string(argv[1]));

  return 0;
}
