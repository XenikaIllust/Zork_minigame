#ifndef ITEM_H
#define ITEM_H

class Item{

	typedef struct _turnon{
		string print;
		string action;
	}TurnON;

private:
	string name;
	string writing;
	string status;
	TurnON isOn;

public:
	void Item(string);
	void Item(string, string);
	void Item(string, string, string);
	void virtual ~Item();

	void setWriting(string);
	void setStatus(string);
	void setIsOn(string, string);
};


#endif
