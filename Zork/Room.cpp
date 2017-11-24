#include "Room.h"

void Room::Room(string roomName, string roomDescription){
	name = roomName;
	description = roomDescription;
	type = "none";
}

void Room::Room(string roomName, string roomDescription, xml_<> * currNode){
	name = roomName;
	description = roomDescription;

	xml_node<> * border = doc.first_node("border");

	while(border->next_sibling() != NULL){
		setBorder(doc.curr_node.first_node("border")->("direction")->value, doc.curr_node.first_node("border")->("name")->value);
		curr_node = doc.curr_node->next_sibling();
	}

}

void Room::Room(string roomName, string roomDescription, string newType){
	name = roomName;
	description = roomDescription;
	Room::setType(newType);

}


void Room::setBorder(string dir, string newName){

	if(dir == "north"){
		north = Border::border(dir, newName);
	}
	if(dir == "south"){
		south = Border::border(dir, newName);
	}
	if(dir == "west"){
		west = Border::border(dir, newName);
	}
	if(dir == "east"){
		east = Border::border(dir, newName);
	}
	else{
		std::cout<<"error adding border"<<endl;
	}
}

void Room::setType(string newType){
	type = newType;
}

string Room::getRoomName(){
	return name;
}

string Room::getRoomDesciption(){
	return description;
}


