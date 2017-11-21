#ifndef ROOM_H
#define ROOM_H

#include <iostream>
#include <string>
#include "Border.h"

using namespace std;
using namespace vecotr;

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
	void setBorder(Border);
	void setType(string);

	string getRoomName();
	string getRoomDescription();





	void getTrigger();
	void getItem();

	void updateStatus();

	void setBorder(string);

	void virtual ~Room();
};

#endif
