TestItem: Zork.cpp Zork.h TestItem.cpp Item.cpp Item.h
	g++ -std=c++0x TestItem.cpp Item.cpp Item.h Zork.cpp Zork.h -o TestItem

clean:
	rm .~
