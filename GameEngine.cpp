#include "GameEngine.h"
#include <iostream>

using namespace std;

void GameEngine::Error() {
  cout << "Error" << endl;
}

void GameEngine::Operation(Map* map_ptr, Input input, Player* player_ptr, vector<string>* autoInputstrvec, int* currentRoom, int* gameOverStatusPtr) {
  if(map_ptr == nullptr) {
    cout << "map_ptr is null in GameEngine::Operation" << endl;
    *gameOverStatusPtr = 1;
    return;
  }

  //print inventory
  if(input.getCommand() == "i" || input.getCommand() == "inventory") {
    player_ptr->getInventory()->printInventory();
    return;
  }

  //player game over
  if(input.getCommand() == "player_game_over") {
    if(map_ptr->getRoom(*currentRoom)->getType() == "exit")
      *gameOverStatusPtr = 1;
    else {
      Error();
      return;
    }
  }

  //auto game over
  if(input.getCommand() == "auto_game_over") {
    *gameOverStatusPtr = 1;
  }

  //navigation
  if(input.getDirection() != "") {
    if (input.getDirection() == "north" || input.getDirection() == "n") {
      this->direction = "north";
    }

    else if (input.getDirection() == "south" || input.getDirection() == "s") {
      this->direction = "south";
    }

    else if (input.getDirection() == "east" || input.getDirection() == "e") {
      this->direction = "east";
    }

    else if (input.getDirection() == "west" || input.getDirection() == "w") {
      this->direction = "west";
    }

    //find the room name based on the border name and change currentRoom to that room
    for(int i = 0; i < map_ptr->getRoom(*currentRoom)->getBorderlistSize(); i++) {
      if(map_ptr->getRoom(*currentRoom)->getBorder(i).getDirection() == this->direction) {
	for(int j = 0; j < map_ptr->getRoomlistSize(); j++) {
	  if(map_ptr->getRoom(j)->getName() == map_ptr->getRoom(*currentRoom)->getBorder(i).getName()) {
	    *currentRoom = j;
	    cout << map_ptr->getRoom(*currentRoom)->getDescription() << endl;
	    return;
	  }
	}
      }
    }

    cout << "Can't go that way." << endl;
  }

  //read item description
  if(input.getCommand() == "read") {
    if(input.getItem() == "") {
      Error();
      return;
    }

    int item_in_room = 0;
    int item_in_inventory = 0;
    int item_exists = 0;
    
    for(int j = 0; j < map_ptr->getRoom(*currentRoom)->getItemlistSize(); j++) { //check if item is in room
      if(map_ptr->getRoom(*currentRoom)->getItem(j) == input.getItem()) {
	item_in_room = 1;
	continue;
      }
    }

    for(int l = 0; l < player_ptr->getInventory()->getItemlistSize(); l++) { //check if item is in inventory
      if(player_ptr->getInventory()->getItem(l) == input.getItem()) {
	item_in_inventory = 1;
	continue;
      }
    }

    for(int i = 0; i < map_ptr->getItemlistSize(); i++) { //check if item exists
      if(map_ptr->getItem(i).getName()  == input.getItem())  {
        item_exists = 1;
	continue;
      }
    }

    if((!item_in_room && !item_in_inventory) || !item_exists) {
      Error();
      return;
    }
    
    for(int k = 0; k < map_ptr->getItemlistSize(); k++) {
      if(map_ptr->getItem(k).getName()  == input.getItem()) {
	if(map_ptr->getItem(k).getWriting() == "")
	  cout << "Nothing written." << endl;
	else
	  cout << map_ptr->getItem(k).getWriting() << endl;
        return;
      }
    }
  }

  //take item
  if(input.getCommand() == "take") {
    if(input.getItem() == "") {
      Error();
      return;
    }

    int item_in_room = 0;
    int item_in_container = 0;
    int item_exists = 0;
    int container_open = 0;
    
    for(int j = 0; j < map_ptr->getRoom(*currentRoom)->getItemlistSize(); j++) { //check if item is in room
      if(map_ptr->getRoom(*currentRoom)->getItem(j) == input.getItem()) {
	item_in_room = 1;
	continue;
      }
    }

    Container* current_container = nullptr;
    
    if(!item_in_room) {
      for(int l = 0; l < map_ptr->getRoom(*currentRoom)->getContainerlistSize(); l++) { //check if item is in container in current room
	for(int m = 0; m < map_ptr->getContainerlistSize(); m++) {
	  if(map_ptr->getRoom(*currentRoom)->getContainer(l) == map_ptr->getContainer(m)->getName()) {
	    if(map_ptr->getContainer(m)->getOpenStatus())
	      container_open = 1;
	    
	    for(int n = 0; n < map_ptr->getContainer(m)->getItemlistSize(); n++) {
	      if(map_ptr->getContainer(m)->getItem(n) == input.getItem()) {
		item_in_container = 1;
		current_container = map_ptr->getContainer(m);
	      }
	    }
	    continue;
	  }
	}
      }
    }

    for(int i = 0; i < map_ptr->getItemlistSize(); i++) { //check if item exists
      if(map_ptr->getItem(i).getName()  == input.getItem())  {
        item_exists = 1;
	continue;
      }
    }

    if((!item_in_room && (item_in_container && !container_open)) || (!item_in_room && (!item_in_container && container_open)) || (!item_in_room && (!item_in_container && !container_open)) || !item_exists) {
      Error();
      return;
    }
    
    for(int k = 0; k < map_ptr->getItemlistSize(); k++) { //add item to inventory
      if(map_ptr->getItem(k).getName()  == input.getItem()) {
	if((item_in_container && container_open) || item_in_room) {
	  player_ptr->getInventory()->addItem(input.getItem());
	  cout << input.getItem() << " added to inventory." << endl;
	  
	  if(item_in_container)
	    current_container->removeItem(input.getItem()); //remove item from container
	  else if(item_in_room)
	    map_ptr->getRoom(*currentRoom)->removeItem(input.getItem());
	  
	  return;
	}
      }
    }
  }

  //drop item
  if(input.getCommand() == "drop") {
    if(input.getItem() == "") {
      Error();
      return;
    }

    int item_in_inventory = 0;
    int item_exists = 0;
    
    for(int l = 0; l < player_ptr->getInventory()->getItemlistSize(); l++) { //check if item is in inventory
      if(player_ptr->getInventory()->getItem(l) == input.getItem()) {
	item_in_inventory = 1;
	continue;
      }
    }

    for(int i = 0; i < map_ptr->getItemlistSize(); i++) { //check if item exists
      if(map_ptr->getItem(i).getName()  == input.getItem())  {
        item_exists = 1;
	continue;
      }
    }

    if(!item_in_inventory || !item_exists) {
      Error();
      return;
    }
    
    for(int k = 0; k < map_ptr->getItemlistSize(); k++) { //drop item from inventory
      if(map_ptr->getItem(k).getName()  == input.getItem()) {
        player_ptr->getInventory()->removeItem(input.getItem());
	cout << input.getItem() << " dropped from inventory." << endl;
	map_ptr->getRoom(*currentRoom)->addItem(input.getItem()); //add item to room
        return;
      }
    }
  }
  
  //turn on item
  if(input.getCommand() == "turn_on") {
    if(input.getItem() == "") {
      Error();
      return;
    }

    int item_in_inventory = 0;
    int item_exists = 0;
    
    for(int j = 0; j < player_ptr->getInventory()->getItemlistSize(); j++) { //check if item is in inventory
      if(player_ptr->getInventory()->getItem(j) == input.getItem()) {
	item_in_inventory = 1;
	continue;
      }
    }

    for(int i = 0; i < map_ptr->getItemlistSize(); i++) { //check if item exists
      if(map_ptr->getItem(i).getName()  == input.getItem())  {
        item_exists = 1;
	continue;
      }
    }

    if(!item_in_inventory || !item_exists) {
      Error();
      return;
    }
    
    for(int k = 0; k < map_ptr->getItemlistSize(); k++) {
      if(map_ptr->getItem(k).getName()  == input.getItem()) {
	cout << "You turned on the " << map_ptr->getItem(k).getName() << endl;
	cout << map_ptr->getItem(k).getTurnonPrint() << endl;
        autoInputstrvec->push_back(map_ptr->getItem(k).getTurnonAction());
        return;
      }
    }
  }

  //open container
  if(input.getCommand() == "open") {
    if(input.getContainer() != "") {
      int container_in_room = 0;
      int container_exists = 0;

      for(int j = 0; j < map_ptr->getRoom(*currentRoom)->getContainerlistSize(); j++) { //check if container is in room
	if(map_ptr->getRoom(*currentRoom)->getContainer(j) == input.getContainer()) {
	  container_in_room = 1;
	  continue;
	}
      }
      
      for(int i = 0; i < map_ptr->getContainerlistSize(); i++) { //check if container exists
	if(map_ptr->getContainer(i)->getName()  == input.getContainer())  {
	  container_exists = 1;
	  continue;
	}
      }
      
      if(!container_in_room || !container_exists) {
	Error();
	return;
      }

      for(int k = 0; k < map_ptr->getContainerlistSize(); k++) { //open container
	if(map_ptr->getContainer(k)->getName()  == input.getContainer()) {
	  map_ptr->getContainer(k)->changeOpenStatus(true);
	  cout << map_ptr->getContainer(k)->getName() << " contains ";

	  for(int z = 0; z < map_ptr->getContainer(k)->getItemlistSize(); z++) {
	    cout << map_ptr->getContainer(k)->getItem(z);
	  }
	  cout << endl;
	  
	  return;
	}
      }
    }
  }

  //put item in container
  if(input.getCommand() == "put") {
    if(input.getItem() == "" || input.getContainer() == "") {
      Error();
      return;
    }

    int item_in_inventory = 0;
    int item_exists = 0;
    int container_in_room = 0;
    int container_open = 0;
    
    for(int l = 0; l < player_ptr->getInventory()->getItemlistSize(); l++) { //check if item is in inventory
      if(player_ptr->getInventory()->getItem(l) == input.getItem()) {
	item_in_inventory = 1;
	continue;
      }
    }

    for(int i = 0; i < map_ptr->getItemlistSize(); i++) { //check if item exists
      if(map_ptr->getItem(i).getName()  == input.getItem())  {
        item_exists = 1;
	continue;
      }
    }

    Container* current_container = nullptr;
    
    for(int j = 0; j < map_ptr->getRoom(*currentRoom)->getContainerlistSize(); j++) { //check if container is in room
	if(map_ptr->getRoom(*currentRoom)->getContainer(j) == input.getContainer()) {
	  container_in_room = 1;	  
	  continue;
	}
    }

    for(int m = 0; m < map_ptr->getContainerlistSize(); m++) { //check if container is open
      if(map_ptr->getContainer(m)->getOpenStatus())
	container_open = 1;
      
      continue;
    }

    if(!(item_in_inventory && container_in_room && container_open) || !item_exists) {
      Error();
      return;
    }
    
    for(int k = 0; k < map_ptr->getContainerlistSize(); k++) { //add item to container
      if(map_ptr->getContainer(k)->getName()  == input.getContainer()) {
	if(container_in_room && container_open) {
	  player_ptr->getInventory()->removeItem(input.getItem());
	  map_ptr->getContainer(k)->addItem(input.getItem());
	  cout << input.getItem() << " added to " << map_ptr->getContainer(k)->getName() << endl;
	  return;
	}
      }
    }
  }

  //attack
  if(input.getCommand() == "attack") {
    if(input.getCreature() == "" || input.getItem() == "") {
      Error();
      return;
    }
    
    int creature_exists = 0;
    int creature_in_room = 0;
    int creature_alive = 0;
    int item_in_inventory = 0;

    for(int l = 0; l < player_ptr->getInventory()->getItemlistSize(); l++) { //check if item is in inventory
      if(player_ptr->getInventory()->getItem(l) == input.getItem()) {
	item_in_inventory = 1;
	continue;
      }
    }
    
    for(int k = 0; k < map_ptr->getRoom(*currentRoom)->getCreaturelistSize(); k++) { //check if creature in current room
      if(map_ptr->getRoom(*currentRoom)->getCreature(k) == input.getCreature()) {
	creature_in_room = 1;
	continue;
      }
    }

    Creature* creature_ptr = nullptr;
    
    for(int i = 0; i < map_ptr->getCreaturelistSize(); i++) { //check if creature exists
      if(map_ptr->getCreature(i)->getName()  == input.getCreature())  {
        creature_exists = 1;
	creature_ptr = map_ptr->getCreature(i);
	continue;
      }
    }

    if(creature_ptr->getDeathStatus() == false)  { //check if creature is still alive
      creature_alive = 1;
    }

    if(!creature_alive || !creature_exists || !creature_in_room || !item_in_inventory) {
      Error();
      return;
    }

    else{
      for(int k = 0; k < creature_ptr->getVulnerabilitylistSize(); k++) { //check item match with vulnerability
	if(creature_ptr->getVulnerability(k) == input.getItem()) {
	  cout << "You assault the " << input.getCreature() << " with your " << input.getItem() << "!" << endl;
	  for(int n = 0; n < creature_ptr->getAttack().getPrintlistSize(); n++) { //print attack printlist
	    cout << creature_ptr->getAttack().getPrint(n) << endl;
	  }
	  for(int o = 0; o < creature_ptr->getAttack().getActionlistSize(); o++) { //update autoinputs
	    autoInputstrvec->push_back(creature_ptr->getAttack().getAction(o));
	  }
	  return;
	}
      }
      cout << "It wasn't very effective!" << endl;
      return;
    }
  }

  //add creature to room (internal function)
  if(input.getCommand() == "add" || input.getCommand() == "Add") {
    if(input.getCreature() == "" || input.getRoom() == "") {
      Error();
      return;
    }

    int creature_exists = 0;
    int room_exists = 0;
    
    for(int i = 0; i < map_ptr->getCreaturelistSize(); i++) { //check if creature exists
      if(map_ptr->getCreature(i)->getName()  == input.getCreature())  {
        creature_exists = 1;
	continue;
      }
    }

    Room* creature_room = nullptr;
    
    for(int i = 0; i < map_ptr->getRoomlistSize(); i++) { //check if room exists
      if(map_ptr->getRoom(i)->getName()  == input.getRoom())  {
        room_exists = 1;
	creature_room = map_ptr->getRoom(i);
	continue;
      }
    }

    if(!creature_exists || !room_exists) {
      Error();
      return;
    }
    else {
      creature_room->addCreature(input.getCreature());
      return;
    }
  }

  //delete existence of creature in every room
  if(input.getCommand() == "delete" || input.getCommand() == "Delete") {
    if(input.getCreature() == "") {
      Error();
      return;
    }

    int creature_exists = 0;
    
    for(int i = 0; i < map_ptr->getCreaturelistSize(); i++) { //check if creature exists
      if(map_ptr->getCreature(i)->getName()  == input.getCreature())  {
        creature_exists = 1;
	continue;
      }
    }

    if(!creature_exists) {
      Error();
      return;
    }
    
    else {
      for(int j = 0; j < map_ptr->getRoomlistSize(); j++) { //check if creature in all rooms and delete if yes
	for(int k = 0; k < map_ptr->getRoom(j)->getCreaturelistSize(); k++) {
	  if(map_ptr->getRoom(j)->getCreature(k) == input.getCreature()) {
	    map_ptr->getRoom(j)->removeCreature(input.getCreature());
	    return;
	  }
	}
      }
    }
  }
    
  
  //update item status (internal function)
    
  return;
}

void RunGame(Map* map_ptr) {
  Input input;
  GameEngine gameEngine;
  Player player;

  vector<string> autoInputstrvec;
  int gameOverStatus = 0;
  int currentRoom = 0;

  if(map_ptr->getRoomlistSize() == 0) {
    gameEngine.Error();
    return;
  }

  cout << map_ptr->getRoom(currentRoom)->getDescription() << endl;
  
  while(!gameOverStatus) {
    if(autoInputstrvec.size() > 0) { //automated input
      for(int i = 0; i < autoInputstrvec.size(); i++) {
	input.getInput(&autoInputstrvec[i]);
	autoInputstrvec.erase(autoInputstrvec.begin() + i);
	gameEngine.Operation(map_ptr, input, &player, &autoInputstrvec,  &currentRoom, &gameOverStatus);
      }
    }
    else { //manual input
      input.getInput(nullptr);
      gameEngine.Operation(map_ptr, input, &player, &autoInputstrvec,  &currentRoom, &gameOverStatus);
    }
  }
  
  return;
}
