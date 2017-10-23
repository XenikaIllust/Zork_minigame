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

	else if (str1 == "take" || str1 == "open" || str1 == "read" || str1 == "drop" || str1 == "put" || str1 == "") {
		command = str1;
	}

	else {
		cout << "Error" << endl;
	}
}

void Input::error() {
	cout << "Error" << endl;
}
