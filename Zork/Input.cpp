#include <string>
#include "Input.h"
#include "rapidxml-1.13/rapidxml.hpp"

using namespace std;
using namespace rapidxml;

void Input::getInput() {
	string words[4] = { "" };

	for (int i = 0; i < 4; i++) {
		cin >> words[i];
	}
}

void Input::interpretInput(string* words) {

}