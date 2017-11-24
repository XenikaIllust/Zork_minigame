#ifndef ROOM_H
#define ROOM_H

#include <iostream>
#include <vector>
#include <string>
#include "Border.h"

using namespace std;

class Room{

private:
	string name;
	string description;
	string type;
	Border north;
	Border south;
	Border west;
	Border east;

public:
	void Room(string, string);
	void Room(string, string, xml_<> node);
	void setBorder(string, string);
	void setType(string);

	string getRoomName();
	string getRoomDescription();

	void virtual ~Room();
};

#endif
