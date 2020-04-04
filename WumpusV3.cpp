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
      int wumpusRoom, wumpusStart;
      bool playerAlive, wumpusAlive;
      
      void PlacePlayer();
      void PlaceWumpus();
      bool IsRoomAdjacent(int, int);
      int Move(int);
      void InspectCurrentRoom();
      void PerformAction(int);
      void PlayGame();
      bool isRoomValid(int);
      void PlayAgain();
 
      public:
        void StartGame();
        WumpusGame();
        vector<vector<int>> validRooms ();
};
 
WumpusGame::WumpusGame() {
    numRooms = 8;
}

vector<vector<int>> WumpusGame::validRooms (){
    vector<vector<int>> rooms =  {  {1, 2, 19},   {0, 4, 5},   {0, 3, 18},   {2, 4, 15},    {1, 3, 6},
                                    {1, 7, 8},  {4, 7, 12},    {5, 6, 9},   {5, 10, 19},   {7, 10, 11},
                                    {9, 8, 13}, {9, 12, 14}, {6, 15, 11},  {14, 16, 10},  {11, 13, 17},
                                    {3, 12, 17}, {18, 13, 19},  {14, 15, 18}, {14, 17, 2}, {8, 16, 0}};

    return rooms;
}

const static int adjacentRooms[20][3] = { {1, 2, 19},   {0, 4, 5},   {0, 3, 18},   {2, 4, 15},    {1, 3, 6},
                                    {1, 7, 8},  {4, 7, 12},    {5, 6, 9},   {5, 10, 19},   {7, 10, 11},
                                    {9, 8, 13}, {9, 12, 14}, {6, 15, 11},  {14, 16, 10},  {11, 13, 17},
                                    {3, 12, 17}, {18, 13, 19},  {14, 15, 18}, {14, 17, 2}, {8, 16, 0}
                                    };


void WumpusGame::PlacePlayer() {
    startingPosition = rand() % 20;
    currentRoom = Move(startingPosition);
} 

void WumpusGame::PlaceWumpus(){
    bool validRoom = false;
    while(!validRoom){
        int randomRoom = rand() % 20;
        if(randomRoom != startingPosition){
            validRoom = true;
            wumpusRoom = randomRoom;
            wumpusStart = wumpusRoom;
        }
    }
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
    if(currentRoom == wumpusRoom){
        cout << "The Wumpus ate you!" << endl;
        cout << "You suck, loser" << endl;
        PlayAgain();
    } else{
        cout << "You are in room ";
        cout << currentRoom << endl;
        cout << wumpusRoom << endl;
        if(IsRoomAdjacent(currentRoom, wumpusRoom)){
            cout << "Something smells fishy " << endl;
        }
        cout << "Tunnels lead to rooms " << endl;
        for (int j = 0; j < 3; j++)
        {
            cout << adjacentRooms[currentRoom][j];
            cout << " ";
        }
            cout << endl;
    }
}

void WumpusGame::PlayAgain(){
    char antwoord;
    cout << "Would you like to play again?Enter Y/N, enter Y to play again.";
    cin >> antwoord;
    if(antwoord == 'y' || antwoord == 'Y'){
        currentRoom = startingPosition;
        wumpusRoom = wumpusStart;
        cout << "Goodluck." << endl;
        InspectCurrentRoom();
    } else {
        playerAlive = false;
    }
    
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
            catch (...) //checkt of er wel een nummer word ingevoerd.
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
    PlaceWumpus();
 
    playerAlive = true;
    wumpusAlive = true;
 
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