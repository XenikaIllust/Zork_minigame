TestItem: Zork.cpp Zork.h TestItem.cpp Item.cpp Item.h
	g++ -std=c++0x TestItem.cpp Item.cpp Item.h Zork.cpp Zork.h -o TestItem

TestCondition: Zork.cpp Zork.h TestCondition.cpp Condition.cpp Condition.h
	g++ -std=c++0x TestCondition.cpp Condition.cpp Condition.h Zork.cpp Zork.h -o TestCondition

clean:
	rm .~
