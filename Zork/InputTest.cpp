#include <string>
#include "Input.h"
#include "rapidxml-1.13/rapidxml.hpp"

using namespace std;
using namespace rapidxml;

int main() {
	Input input;

	cout << "Type input here :" << endl;
	input.getInput();

	cout << input.returnDirection() << endl;
	cout << input.returnCommand() << endl;
	cout << input.returnCreature() << endl;
	cout << input.returnItem() << endl;
	cout << input.returnObject() << endl;

	return 0;
}