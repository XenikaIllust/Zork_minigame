#include "Map.h"
#include <iostream>

void Map::Map(xml doc){

	xml_node<> *curr_node = doc.first_node();

	while(curr_node->next_sibling() != NULL){
		addRoom(doc.curr_node.first_node("name")->value, doc.curr_node.first_node("description")->value, doc.curr_node);
		curr_node = doc.curr_node->next_sibling();
	}
}

void Map::addRoom(string roomName, string roomDes, xml_<> * currNode){
	Room newRoom = Room::Room(roomName, romDes, currNode);
	rooms.push_back(newRoom);
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
