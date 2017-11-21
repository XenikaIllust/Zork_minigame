#include "Map.h"

void Map::Map(){

}

void Map::addRoom(string roomName, string roomDes, string dir, string borderName){
	Room newRoom = Room::Room(roomName, romDes);
	rooms.push_back(newRoom);
}

string Map::getRoomName(Room room){
	string empty = "empty";
	return empty;
}

void Map::~Map(){

}
