#include "Container.h"

void Container::Container(string newWriting, string new_I_Status){
	item = Item::Item(newWriting, new_I_Status);
}

void Container::Container(string new_C_Status, string newAccpet, string newWriting, string new_I_Status){
	item = Item::Item(newWriting, new_I_Status);

	Contaner::setStatus(new_C_Status);
	Container::setAccept(newAccept);

}

void Container::setStatus(string newAccept){
	status = newAccept;
}

void Container::setAccept(string){
	accept = newAccept;
}

