//Room cpp/header
// Main cpp
//Items strut or cpp/header do the memory storing thing like search

#include "room.h"
#include <iostream>
#include <cstring>
using namespace std;

room::room() {
  currentRoom = nullptr;
  storedItems = nullptr;
  description = nullptr;
}
room::room(char* cr, char* si, char* d) { //constructor for the DigitalMedia

    currentRoom = new char[80];
    strcpy(currentRoom, cr);
  
    storedItems = new char[80];
    strcpy(storedItems, si);

    description = new char[80];
    strcpy(description, d);  //copys t into the array
}
room::~room() { //destructor for the DigitalMedia
    delete[] currentRoom;
    delete[] description;
    delete[] storedItems;
}

char* room::getCurrentRoom(){
  return currentRoom;
}
char* room::getDescription(){
  return description;
}
char* room::getStoredItems(){ //getter for the exits
    return storedItems;
}

 void room::setExit(char* direction, room* avalibleRooms){
  char* avaliableExits = new char[80];
  strcpy(avaliableExits, direction);
  exits[avaliableExits] = avalibleRooms;
}

room* room::getExit(char* direction){
  for (const auto& exit : exits) {
        if (strcmp(exit.first, direction) == 0) {
            return exit.second;
        }
}
}
void room::setItem(char* items) {
  char* storedItems = new char[80];
  strcpy(storedItems, items);
}


void room::displayInfo(){
    cout << "You are in: " << currentRoom << endl;
    cout << "Description: " << description << endl;
    cout << "Item in this room: " << storedItems << endl;
}

