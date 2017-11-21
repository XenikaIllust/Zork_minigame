#ifndef BORDER_H
#define BORDER_H

#include <string>

class Border{

private:
	string direction;
	string name;

public:
	void Border(string, string);

	string getBorderDir(Border);

	string getBorderName(Border);

	void virtual ~Border();

};

#endif
