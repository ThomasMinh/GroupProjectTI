#include "CoronaFunctions.h"

using namespace std;
void moveComputer(){
    int roomChoice = 0;
    int computerRoom = 0;
    vector<int> neighbourRooms = read(computerRoom); //leest alle buurkamers die er zijn
    int randNumber = rand() % 3; //genereert een random nummer tussen 0 en 2
    
    cout << "Which room? " << endl;
    roomChoice = neighbourRooms[randNumber]; // kiest een kamer van 1 van de buurkamers
    cout << roomChoice << endl; //de computer laat zijn keuze zien
    computerRoom = Move(roomChoice);
}

void PlayGameComputer(){
    srand (time(NULL));
    bool validChoice = false;
    bool computerAlive = true;
    vector<vector<int>> map = generateMap();

    
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
        cout << ">>> ";
 
        do{
            validChoice = true;
            cout << "Please make a selection: ";
            try{
                int choice = 1;
                switch(choice){
                    case 1:
                    cout << choice << endl;
                    moveComputer();
                    break;
                    
                    case 2:
                    cout << "Shooting";
                    break;
                    
                    default:
                    validChoice = false;
                    cout << "Invalid choice. Please try again." << endl;
                    break;
                }
            }
            catch(...){
                validChoice = false;
                cout << "Invalid choice. Please try again." << endl;
            }
        }
        while (validChoice == false);
    }
}
