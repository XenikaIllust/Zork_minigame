#include <iostream>
#include <string>
#include "Input.h"
#include "rapidxml-1.13/rapidxml.hpp"

using namespace std;
using namespace rapidxml;

void Input::getInput() {
	string str1("");
	string str2("");
	string str3("");
	string str4("");

	cin >> str1;

	if (str1 == "n" || str1 == "s" || str1 == "e" || str1 == "w" || str1 == "north" || str1 == "south" || str1 == "east" || str1 == "west") {
		direction = str1;
	}

	else if (str1 == "take" || str1 == "open" || str1 == "read" || str1 == "drop") {
		command = str1;

		cin >> str2;
		item = str2;
	}

	else if (str1 == "attack" || str1 == "put") { //four word input special case
		command = str1;

		cin >> str2;
		creature = str2;

		cin >> str3;
		
		cin >> str4;
		item = str4;
	}

	else if (str1 == "turn") { //double letter special case
		if (str2 == "on") {
			command = "turn_on";
		}
	}

	else {
		cout << "I do not recognize what you want to do." << endl;
	}
}

void Input::error() {
	cout << "Error" << endl;
}
