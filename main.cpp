// USING CLASSES AS A SKELTON FOR ZUUL WHICH IS WHY THERES SO MUCH CODE ALREADY :)


#include <iostream>
#include <vector>
#include <memory>
#include <cstring>
#include "room.h"

using namespace std;

vector<char*> inventory;

void add(vector<char*>& inventory);
void moveRooms();
void drop(vector<room*>& rooms);

room* currentRoom = nullptr;

void menu() {
  currentRoom->displayInfo();
  cout << "Your inventory: ";
  for (auto& item : inventory) {
    cout << item << " ";
    cout << "" << endl;
        }
}

  void createRooms() {
    room* frontentrence = new room("front entrance", "Computer", "outside the main entrance of the university");
    room* nurseroom = new room("nurse room", "na", "in a nurse room");
    room* supplycloset = new room("supply closet", "Mouse", "in a suplly closet (smells funky)");
    room* mainhall = new room("main hallway", "na", "in the main hallway");
    room* labroom = new room("laboratory room", "na", "in the labratory room (nerd.)");
    room* bathroom = new room("bathroom", "VR", "in the bathroom (did you flush...)");
    room* onehall = new room("1-hall", "na", "in 1-hall");
    room* computerroom = new room("computer room", "na", "in the computing room");
    room* studyroom = new room("study hall", "na", "in the study hall");
    room* gym = new room("gym", "Headphones", "in the gym");
    room* supplyroom = new room("equipment room", "Keyboard", "in a room with equipment (so much stuff...)");
    room* field = new room("track field", "na", "in the track field.");
 room* cafetria = new room("cafeteria", "na", "in the cafetria (yum!)");
    room* dinningroom = new room("dining room", "na", "in the dinning room (its time to grub!)");
    room* kitchen = new room("kitchen", "na", "in the kitchen (you cooking bro?)");

    frontentrence->setExit("west", mainhall);
    frontentrence->setExit("south", nurseroom);

    nurseroom->setExit("north", frontentrence);
    nurseroom->setExit("south", supplycloset);

    supplycloset->setExit("north", nurseroom);

    mainhall->setExit("north", labroom);
    mainhall->setExit("south", bathroom);
    mainhall->setExit("east", frontentrence);
    mainhall->setExit("west", onehall);

    bathroom->setExit("north", mainhall);

    labroom->setExit("west", computerroom);
    labroom->setExit("south", mainhall);

    onehall->setExit("north", computerroom);
    onehall->setExit("south", studyroom);
    onehall->setExit("east", mainhall);
    onehall->setExit("west", gym);

    computerroom->setExit("east", labroom);
    computerroom->setExit("south", onehall);

    gym->setExit("west", field);
    gym->setExit("north", supplyroom);
    gym->setExit("east", onehall);

    field->setExit("east", gym);


supplyroom->setExit("south", gym);

    studyroom->setExit("north", onehall);
    studyroom->setExit("south", cafetria);

    cafetria->setExit("north", studyroom);
    cafetria->setExit("south", dinningroom);
    cafetria->setExit("west", kitchen);

    kitchen->setExit("east", cafetria);

    dinningroom->setExit("north", cafetria);
    
    frontentrence->setItem("Computer");
    bathroom->setItem("VR");
    supplycloset->setItem("Mouse");
    supplyroom->setItem("Keyboard");
    gym->setItem("Headphones");
    
    currentRoom = frontentrence;
}

int main() {
    vector<room*> rooms;

createRooms();

    char choice[80];
    bool start = true;

    while (start) {

      menu();
      cout << "Enter a command move add drop or quit: " << endl;
        cin.getline(choice, 80);

        if (strcmp(choice, "move") == 0) {
            moveRooms();
        } else if (strcmp(choice, "add") == 0) {
	  add(inventory);
	} else if (strcmp(choice, "quit") == 0) {
            start = false; 
        } else {
            cout << "Invalid choice, please try again." << endl;
        }
    }

    for (room* r : rooms) {
        delete r;
    }

    return 0;
}

 void add(vector<char*>& inventory) {
        char* item = currentRoom->getStoredItems();
        inventory.push_back(item);
	cout << "You added a " << item << " to your inventory." << endl;
        currentRoom->setItem("");  
}

 void moveRooms() {
   char direction[80];
    cout << "Enter direction north, south, east, west ";
    cin.getline(direction, 80);

    room* nextRoom = currentRoom->getExit(direction);

    if (nextRoom != nullptr) {
        currentRoom = nextRoom;
        cout << "You have moved to " << currentRoom->getCurrentRoom() << endl;
	// currentRoom->displayInfo();
    } else {
        cout << "No exit in that way" << endl;
    }
}

/*
  void drop(vector<room*>& rooms) {
    char keyword[80];

    cout << "Enter title to delete: ";
    cin >> ws;
    cin.getline(keyword, 80);

 for (size_t i = 0; i < mediaData.size(); ++i) {
        if (strcmp(mediaData[i]->getTitle(), keyword) == 0) {
            mediaData[i]->displayInfo();

            char confrim[80];
            cout << "Are you sure you want to delete this? (Yes/No): ";
            cin >> confrim;

            if (strcmp(confrim, "Yes") == 0) {
                delete mediaData[i];
                mediaData.erase(mediaData.begin() + i);
                cout << "Item deleted.\n";
                return;
            } else {
                cout << "Deletion failed.\n";
                return;
            }
        }
    }

    cout << "Nothing matches with your serach.\n";
}

*/

