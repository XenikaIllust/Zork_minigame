#include <string>
#include "Input.h"
#include "rapidxml-1.13/rapidxml.hpp"

using namespace std;
using namespace rapidxml;

int main() {
	Input input;

	cout << Type input here:
	input.getInput();

	cout << input.returnDirection();
	cout << input.returnCommand();
	cout << input.returnItem();
	cout << input.returnObject();

	return 0;
}