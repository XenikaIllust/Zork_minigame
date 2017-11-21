#include "Item.h"

void Item::Item(string newItem){
	name = newItem;
}

void Item::Item(string newItem, string newWriting){
	name = newItem;
	setWriting(newWriting);
}

void Item::Item(string newItem, string newWriting, string newStatus){
	name = newItem;
	setWriting(newWriting);
	setStatus(newStatus);
}

void Item::setWriting(string newWriting){
	writing = newWrting;
}

void Item::setStatus(string newStatus){
	status = newStatus;
}

void Item::setIsOn(string newPrint, string, newAction){
	isOn.print = newPrint;
	isOn.action = newAction;
}

void Item::~Item(){

}
