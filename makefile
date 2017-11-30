TestGame: TestGame.cpp GameEngine.h GameEngine.cpp Player.cpp Player.h Input.cpp Input.h Map.cpp Map.h Room.cpp Room.h Border.cpp Border.h Item.h Item.cpp Container.h Container.cpp Creature.h Creature.cpp Zork.cpp Zork.h Trigger.h Trigger.cpp Condition.h Condition.cpp
	g++ -std=c++0x TestGame.cpp GameEngine.h GameEngine.cpp Player.cpp Player.h Input.cpp Input.h Map.cpp Map.h Room.cpp Room.h Border.cpp Border.h Item.h Item.cpp Container.h Container.cpp Creature.h Creature.cpp Zork.cpp Zork.h Trigger.h Trigger.cpp Condition.h Condition.cpp -o TestGame -g

TestItem: Zork.cpp Zork.h TestItem.cpp Item.cpp Item.h
	g++ -std=c++0x TestItem.cpp Item.cpp Item.h Zork.cpp Zork.h -o TestItem

TestCondition: Zork.cpp Zork.h TestCondition.cpp Condition.cpp Condition.h
	g++ -std=c++0x TestCondition.cpp Condition.cpp Condition.h Zork.cpp Zork.h -o TestCondition -g

TestContainer: Zork.cpp Zork.h TestContainer.cpp Container.cpp Container.h Trigger.h Trigger.cpp Condition.h Condition.cpp
	g++ -std=c++0x TestContainer.cpp Container.cpp Container.h Zork.cpp Zork.h Trigger.h Trigger.cpp Condition.h Condition.cpp -o TestContainer -g

TestCreature: Zork.cpp Zork.h TestCreature.cpp Creature.cpp Creature.h Trigger.h Trigger.cpp Condition.h Condition.cpp
	g++ -std=c++0x TestCreature.cpp Creature.cpp Creature.h Zork.cpp Zork.h Trigger.h Trigger.cpp Condition.h Condition.cpp -o TestCreature -g

TestInput: Input.cpp Input.h TestInput.cpp
	g++ -std=c++0x TestInput.cpp Input.cpp Input.h -o TestInput  -g

clean:
	rm .~
