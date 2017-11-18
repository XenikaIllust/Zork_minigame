#ifndef ROOM_H
#define ROOM_H

#include <iostream>
#include <string>

using namespace std;

class Room
{
	string name;
	string description;

	public:
		void Room(){
			Room * northRoom = NULL;
			Room * southRoom = NULL;
			Room * westRoom = NULL;
			Room * eastRoom = NULL;
		};

		void virtual ~Room();
		void getName(string);
		void getDescription(string);

};

#endif
