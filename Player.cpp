#include "Player.h"
#include <iostream>

using namespace std;

string Inventory::getItem(int i) {
  return this->itemlist[i];
}

int Inventory::getItemlistSize() {
  return this->itemlist.size();
}

void Inventory::addItem(string item) {
  this->itemlist.push_back(item);
}

void Inventory::removeItem(string item) {
  for(int i = 0; i < itemlist.size(); i++) {
    if(itemlist[i] == item) 
      this->itemlist.erase(itemlist.begin() + i);
  }
}

void Inventory::printInventory() {
  cout << "Inventory: " << endl;
  for(int i = 0; i < itemlist.size(); i++) {
    cout << itemlist[i] << endl;
  }
}

Inventory* Player::getInventory() {
  return &(this->inventory);
}
