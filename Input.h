#ifndef INPUT_H
#define INPUT_H

#include <iostream>
#include <string>

class Input {
public:
	void getInput();
	void error();

	std::string getDirection();
	std::string getCommand();
	std::string getContainer();
	std::string getItem();
	std::string getCreature();

private:
	std::string command;
	std::string direction;
	std::string item;
	std::string creature;
	std::string container;
};

#endif
