#ifndef BORDER_H
#define BORDER_H

#include <string>

using namespace std;

class Border{

private:
	string direction;
	string name;
public:
	Border(string, string);
	virtual ~Border();

	string getBorderDir();
	string getBorderName();
};

#endif
