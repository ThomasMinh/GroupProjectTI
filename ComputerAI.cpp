#include "CoronaFunctions.h"

using namespace std;

void PlacePlayer() {
    int startingPosition = rand() % 20 + 1; //random nummer wordt gegenereerd tussen 1-20
    int currentRoom = Move(startingPosition); //speler wordt gemoved naar dat random nummer 
} 

void PlayGameComputer(){
    srand (time(NULL));
    int currentRoom = 0;
    int roomChoice = 0;
    bool validChoice = false;
    bool computerAlive = true;
    vector<vector<int>> map = generateMap();
    vector<int> neighborRooms = read(currentRoom); //leest alle buurkamers die er zijn
    int randNumber = rand() % 3; //genereert een random nummer tussen 0 en 2
    
    srand(time(NULL));  // rand() zal hierdoor steeds een andere selectie van getallen genereren
    PlacePlayer();
    PlaceCorona();
    placePolice();
    placeQZones();
    write(map);
    
    InspectCurrentRoom();
 
    while (computerAlive){
        cout << "Enter an action choice." << endl;
        cout << "1) Move" << endl;
        cout << "2) Shoot?" << endl;
        cout << "3) Quit" << endl;
        cout << ">>> ";
 
        do{
            validChoice = true;
            cout << "Please make a selection: ";
                roomChoice = neighborRooms[randNumber]; // kiest een kamer van 1 van de buurkamers
                cout << roomChoice << endl; //laat de computer zijn keuze zien
                Move(roomChoice);
        }
        while (validChoice == false);
    }
}