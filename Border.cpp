#include "Border.h"

Border::Border(string dir, string new_name){
	direction = dir;
	name = new_name;
}

string Border::getBorderDir(){
	return this->direction;
}

string Border::getBorderName(){
	return this->name;
}

Border::~Border(){
}
