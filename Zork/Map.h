#ifndef MAP_H
#define MAP_H

#include "Room.h"
#include <string>

class Map{

private:


public:
	vector<Room*> rooms;

	void Map();

	void addRoom(string, string, string, string);	//build a new room and add it to existing

	string getBorderName(Room);

	void virtual ~Map();
};

#endif
