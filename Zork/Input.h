#pragma once

#include <iostream>
#include <string>

class Input {
public:
	getInput(std::string in);
	void separateString(std::string* action, std::string* object, std::string* item);
	void interpretString(const std::string* action); //function overloaded
	void interpretString(const std::string* action, const std::string* object);
	void interpretString(const std::string* action, const std::string* object, const std::string* item );\

	void 

private:
	std::string action;
	char direction;
	std::string direction;
	std::string item;
	std::string subject;
}