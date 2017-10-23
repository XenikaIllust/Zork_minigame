#ifndef  INPUT_H
#define INPUT_H

#include <iostream>
#include <string>

class Input {
public:
	void getInput();
	void error();

	std::string returnDirection();
	std::string returnCommand();
	std::string returnObject();
	std::string returnItem();

private:
	std::string command;
	std::string direction;
	std::string item;
	std::string object;
};

#endif