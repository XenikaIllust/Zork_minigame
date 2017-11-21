#include "Border.h"

void Border::Border(string dir, string new_name){
	direction = dir;
	name = new_name;
}

string Border::getBorderDir(Border border){
	return border.direction;
}

string Border::getBorderName(Border border){
	return border.name;
}

