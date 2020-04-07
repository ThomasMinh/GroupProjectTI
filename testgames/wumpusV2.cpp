#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <cstring>
using namespace std;
 
class WumpusGame {
 
    private:
      int numRooms;
      int currentRoom, startingPosition;
      
      void PlacePlayer();
      bool IsRoomAdjacent(int, int);
      int Move(int);
      void InspectCurrentRoom();
      void PerformAction(int);
      void PlayGame();
      bool playerAlive;
      bool isRoomValid(int);
 
      public:
        void StartGame();
        WumpusGame();
        vector<vector<int>> validRooms ();
};
 
WumpusGame::WumpusGame() {
    numRooms = 8;
}

vector<vector<int>> WumpusGame::validRooms (){
    vector<vector<int>> rooms =  {{1, 2, 4}, {0, 3, 5}, {0, 3, 6}, {1, 2, 7}, {0, 5, 6}, {4, 1, 7}, {2, 7, 4}, {3, 5, 6}};

    return rooms;
}

const static int adjacentRooms[8][3] = {
{1, 2, 4}, {0, 3, 5}, {0, 3, 6}, {1, 2, 7}, {0, 5, 6}, {4, 1, 7}, {2, 7, 4}, {3, 5, 6}
};

void WumpusGame::PlacePlayer() {
    startingPosition = 0;
    currentRoom = Move(0);
} 

bool WumpusGame::isRoomValid(int newRoom){
    vector<vector<int>> rooms = validRooms();
    for(unsigned int i = 0; i < rooms.size(); i++){
        for(unsigned int j = 0; j < 3; j++){
            if(rooms[i][j] == newRoom){
                return true;
            }
        }
    }
    return false;
}  


bool WumpusGame::IsRoomAdjacent(int roomA, int roomB){
    for (int j = 0; j < 3; j++)
    {
        if (adjacentRooms[roomA][j] == roomB){
          return true;
        }
    }
    return false;
}
 
int WumpusGame::Move(int newRoom){
    return newRoom;
}
 
void WumpusGame::InspectCurrentRoom() {
    srand (time(NULL));
    cout << "You are in room ";
    cout << currentRoom << endl;
    cout << "Tunnels lead to rooms " << endl;
    for (int j = 0; j < 3; j++)
    {
        cout << adjacentRooms[currentRoom][j];
        cout << " ";
    }
        cout << endl;
}

void WumpusGame::PerformAction(int cmd) {
    int newRoom;
    switch (cmd)
    {
 
        case 1:
            cout << "Which room? " << endl;
            try
            {
                cin >> newRoom;
                if (isRoomValid(newRoom))
                {
                    currentRoom = Move(newRoom);
                    InspectCurrentRoom();
                }
                else
                {
                    cout << "You cannot move there." << endl;
                }
            }
            catch (...) // Try...Catch block will catch if the user inputs text instead of a number.
            {
                cout << "You cannot move there." << endl;
            }
            break;
        case 2:
            cout << "Quitting the current game." << endl;
            playerAlive = false;
            break;
        default:
            cout << "You cannot do that. You can move, shoot, save or quit." << endl;
            break;
    }
}
 
void WumpusGame::PlayGame(){
  int choice;
  bool validChoice = false;
 
    PlacePlayer();
 
    playerAlive = true;
 
    InspectCurrentRoom();
 
    while (playerAlive)
    {
        cout << "Enter an action choice." << endl;
        cout << "1) Move" << endl;
        cout << "2) Quit" << endl;
        cout << ">>> ";
 
        do
        {
            validChoice = true;
            cout << "Please make a selection: ";
            try
            {
                cin >> choice;
                switch (choice)
                {
                    case 1:
                        PerformAction(choice);
                        break;
                    case 2:
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
 
void WumpusGame::StartGame() {
 
  srand (time(NULL));
  int choice;
  bool validChoice;
  bool keepPlaying;
 
  do {
      keepPlaying = true;
      cout << "Welcome to Hunt The Wumpus." << endl;
      cout << "1) Play Game" << endl;
      cout << "2) Quit" << endl;
 
      do
      {
          validChoice = true;
          cout << "Please make a selection: ";
          try
          {
              cin >> choice;
              switch (choice)
              {
                  case 1:
                      PlayGame();
                      break;
                  case 2:
                      cout << "Quitting." << endl;
                      keepPlaying = false;
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
  } while (keepPlaying);
}
 
int main() {
    WumpusGame game;
    game.StartGame();
}