#ifndef MAP_H
#define MAP_H

#include "Room.h"
#include <string>

#include "rapidxml-1.13/rapidxml.hpp"
#include "rapidxml-1.13/rapidxml_print.hpp"

using namespace rapidxml;


class Map{

private:


public:
	vector<Room*> rooms;

	void Map(xml&);

	void addRoom(string, string, sxml_<> *node);	//build a new room and add it to existing

	string getBorderName(Room);

	void virtual ~Map();
};

#endif
