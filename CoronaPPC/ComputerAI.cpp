#include "CoronaFunctions.h"

void PlayGameComputer(){
    srand (time(NULL));
    int choice;
    bool validChoice = false;
    bool computerAlive = true
    vector<vector<int>> map = generateMap();
    
    srand(time(NULL));  // rand() zal hierdoor steeds een andere selectie van getallen genereren
    PlacePlayer();
    PlaceCorona();
    placePolice();
    placeQZones();
    write(map);
    
    InspectCurrentRoom();
 
    while (computerAlive)
    {
        cout << "Enter an action choice." << endl;
        cout << "1) Move" << endl;
        cout << "2) Shoot?" << endl;
        cout << "3) Quit" << endl;
        cout << ">>> ";
 
        do //splitsen
        {
            validChoice = true;
            cout << "Please make a selection: ";
            try
            {
                cout << //Hier wordt de keuze van de computer ai gezegd
                switch (choice)
                {
                    case 1:
                        PerformAction(choice);
                        break;
                    case 2:
                        PerformAction(choice);
                        break;
                    case 3:
                        PerformAction(choice);
                        break;
                    default:
                        validChoice = false;
                        cout << "Invalid choice. Please try again." << endl;
                        cin.clear();
                        cin.ignore(10000, '\n');
                        break;
                }
            }
            catch (...)
            {
                validChoice = false;
                cout << "Invalid choice. Please try again." << endl;
                cin.clear();
                cin.ignore(10000, '\n');
            }
 
        } while (validChoice == false);
    }
}