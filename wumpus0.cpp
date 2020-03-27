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
      void PlayAgain();
      bool playerAlive;
      bool isRoomValid(int);
 
      public:
        void StartGame();
        WumpusGame();
        vector<int> validRooms (const int & room);
};
 
WumpusGame::WumpusGame() {
    numRooms = 8;
}

vector<int> WumpusGame::validRooms (const int & room){
    vector<vector<int>> rooms =  {{2, 4, 8}, {1, 3, 7}, {2, 4, 6}, {1, 3, 5}, {4, 6, 8}, {3, 5, 7}, {2, 6, 8}, {1, 5, 7}};

    return rooms[room - 1];
}

const static int adjacentRooms[8][3] = {
{2, 4, 8}, {1, 3, 7}, {2, 4, 6}, {1, 3, 5}, {4, 6, 8}, {3, 5, 7}, {2, 6, 8}, {1, 5, 7}
};

void WumpusGame::PlacePlayer() {
    startingPosition = 0;
    currentRoom = Move(0);
} 

bool WumpusGame::isRoomValid(int roomID){
    vector<int> rooms = validRooms(roomID);
    for(unsigned int i = 0; i < rooms.size(); i++){
        if (roomID < 0){
            return false;
        }
        if (roomID > numRooms){
            return false;
        }
        if (!IsRoomAdjacent(currentRoom, roomID)){
            return false;
        }
    }
    return true;
}


bool WumpusGame::IsRoomAdjacent(int roomID, int roomB){
    vector<int> rooms = validRooms(roomID);
    for (int j = 0; j < 3; j++)
    {
        if (rooms[j] == roomB ){
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
 
  cout << "Running the game..." << endl;
 
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