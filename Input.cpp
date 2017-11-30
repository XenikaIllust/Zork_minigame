#include "Input.h"
#include <sstream>

using namespace std;

void Input::getInput(string* autoInputstr) {
  //reset all variables
  input.clear();
  direction = "";
  command = "";
  container = "";
  item = "";
  creature = "";

  string in;

  if(*autoInputstr == "")
    getline(cin, in);
  else {
    in = *autoInputstr;
    *autoInputstr = "";
  }
  
  stringstream inputstream(in);
  string word;

  while(getline(inputstream, word, ' '))
    input.push_back(word);

  if(input.size() < 1) {
    cout << "Please enter input: " << endl;
    return;
  }
  
  if (input[0] == "n" || input[0] == "s" || input[0] == "e" || input[0] == "w" || input[0] == "north" || input[0] == "south" || input[0] == "east" || input[0] == "west") {
    direction = input[0];
  }
  
  else if (input[0] == "i" || input[0] == "inventory") {
    command = input[0];
  }
  
  else if (input[0] == "take" || input[0] == "read" || input[0] == "drop") {
    command = input[0];

    if(input.size() == 2)
      item = input[1];
    else
      cout << this->command <<" what?" << endl;
  }
  
  else if (input[0] == "open") {
    command = input[0];

    if(input.size() > 1) {
      if (input.size() == 2 && input[1] == "exit") {
	command = "call_game_over";
	return;
      }
    
      else
	container = input[1];
    }
    
    else
      cout << "Open what?" << endl;
  }
  
  else if (input[0] == "attack" || input[0] == "put") { //four word input special case
    this->command = input[0];
    
    if (input[0] == "attack" && input.size() < 5) {
      if(input.size() > 1) {
	this->creature = input[1];

	if(input.size() > 2) {
	  if(input[2] == "with") {
	    if(input.size() == 4) {
	      this->item = input[3];
	    }
	  }
	  else {
	    cout << "Error" << endl;
	  }
	}
	else
	  cout << "attack " << this->creature << " with what?" << endl;
      }
      else
	cout << "attack who?" << endl;
    }

    else if (input[0] == "put" && input.size() < 5) {
      if(input.size() > 1) {
	this->item = input[1];
	
	if(input.size() > 2) {
	  if(input[2] == "in") {
	    if(input.size() == 4) {
	      this->container = input[3];
	    }
	    else
	      cout << "put " << this->item << " in what?" << endl;
	  }
	else {
	  cout << "Error" << endl;
	  }
	}
	else
	  cout << "put " << this->item << " in what?" << endl;
      }
      
      else
	cout << "put what?" << endl;
    }
  }
  
  else if (input[0] == "turn") { //double letter special case
    if (input.size() > 2 && input[0] == "turn" && input[1] == "on") {
      this->command = "turn_on";
      
      if(input.size() == 3) {
	  this->item = input[2];
      }
      else {
	cout << "Turn on what?" << endl;
      }
    }
  }
  
  else {
    cout << "I do not recognize what you want to do." << endl;
  }
}

string Input::getDirection() {
  return direction;
}

string Input::getCommand() {
  return command;
}

string Input::getContainer() {
  return container;
}

string Input::getItem() {
  return item;
}

string Input::getCreature() {
	return creature;
}
