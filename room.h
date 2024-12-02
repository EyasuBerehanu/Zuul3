#ifndef ROOM_H
#define ROOM_H

#include <iostream>
#include <cstring>
 #include <map>

using namespace std;

class room { //defins of the DigitalMedia
protected:
    char* currentRoom;
    map<char*, room*> exits;
    char* storedItems;
  char* description;
  //char* item;
 
public:
    room(); 
    room(char* cr, char* si, char* d); //constructor that takes char pointer and the int
    virtual ~room();
  
    char* getCurrentRoom();
    char* getStoredItems();
    char* getDescription();

  void setExit(char* direction, room* availibleRooms);
  room* getExit(char* direction);
  void setItem(char* items);
  
  virtual void displayInfo(); 

  
};

#endif
