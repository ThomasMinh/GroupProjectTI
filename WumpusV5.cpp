#include <vector>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <random>
#include <chrono>
#include <cstring>
#include <fstream>
#include <sstream>
using namespace std;
 
class WumpusGame {
 
    private:
      int numRooms;
      int currentRoom, startingPosition;
      int wumpusRoom, wumpusStart;
      bool playerAlive, wumpusAlive;
      int batRoom, batRoom2, pitRoom, pitRoom2;
      int bat, bat2, pit, pit2;

      void PlacePlayer();
      void PlaceWumpus();
      bool IsRoomAdjacent(int, int);
      int Move(int);
      void InspectCurrentRoom();
      void PerformAction(int);
      void PlayGame();
      bool isRoomValid(int);
      void PlayAgain();
      vector<vector<int>> generateMap();
      void write(vector<vector<int>> & numbers);
      vector<int> read(int currentroom);
      bool neighbourNeighbour(int currentRoom, int wumpusRoom); 
      void placeBats();
      void placePits();
      
      public:
        void StartGame();
        WumpusGame();
};
 
WumpusGame::WumpusGame() {
    numRooms = 20;
}

vector<vector<int>> WumpusGame::generateMap(){
	vector<vector<int>> map = {};
	vector<vector<int>> sortedMap = {};
	vector<int> room = {};
	vector<int> roomNumbers = {};
	
	for(int i = 1; i <= 20; i++){
		roomNumbers.push_back(i);
	}
	
	auto rng = default_random_engine(chrono::system_clock::now().time_since_epoch().count());
	shuffle (roomNumbers.begin(), roomNumbers.end(), rng);
	
	for(int i = 0; i < 20; i++){
		room = {};
		
		if (i == 0){
			room.push_back(roomNumbers[20-1]);
		}
		else{
			room.push_back(roomNumbers[i-1]);
		}
		
		
		if (i < 10){
			room.push_back(roomNumbers[i+10]);
		}
		else{
			room.push_back(roomNumbers[i-10]);
		}
		
		
		if (i == 20 - 1){
			room.push_back(roomNumbers[0]);
		}
		else{
			room.push_back(roomNumbers[i+1]);
		}
		map.push_back(room);
	}
	
	for(int i = 1; i <= 20; i++){
		for(int j = 0; j < 20; j++){
			if (roomNumbers[j] == i){
				sortedMap.push_back(map[j]);
				break;
			}
		}
	}
	
return sortedMap;
}

void WumpusGame::write(vector<vector<int>> & numbers){
	ofstream WFile("map.txt");

	for(unsigned int i=0; i<numbers.size();i++){
		for(unsigned int j=0; j<numbers[i].size();j++){
			WFile << numbers[i][j] << " ";
		}
        WFile << "\n";
	}
 
	WFile.close();
}

vector<int> WumpusGame::read(int currentRoom){
    string Text = "";
    int number;
	int line = 0;
	int regel = currentRoom;
    vector<int> rooms;
	ifstream RFile("map.txt");

	while (line != regel && getline(RFile, Text)) {
		line++;
	}
	if(line == regel){
        stringstream iss(Text);
        while(iss >> number){
            rooms.push_back(number);
        }
		return rooms;
	}
    RFile.close();
}

void WumpusGame::PlacePlayer() {
    startingPosition = rand() % 20 + 1;
    currentRoom = Move(startingPosition);
} 

void WumpusGame::PlaceWumpus(){
    bool validRoom = false;
    while(!validRoom){
        int randomRoom = rand() % 20 + 1;
        if(randomRoom != startingPosition){
            validRoom = true;
            wumpusRoom = randomRoom;
            wumpusStart = wumpusRoom;
        }
    }
}

void WumpusGame::placeBats(){
    srand(time(NULL)); // rand() zal hierdoor steeds een andere selectie van getallen genereren
    bool validRoom = false; // zodat hij niet genereert waar de player staat
    while (!validRoom){
        batRoom = rand() % 20 + 1; // als room true is zet bat in random room van 1 tot 20
        if(batRoom != batRoom2 && batRoom != startingPosition && batRoom != wumpusRoom){ // als batRoom niet hetzelfde is als waar de wumpus is, is de room valid
            validRoom = true;
        }
    }
    validRoom = false;
    while(!validRoom){
        batRoom2 = rand() % 20 + 1;
        if (batRoom2 != batRoom && batRoom2 != startingPosition && batRoom2 != wumpusRoom){
            validRoom = true;
        }
    }
    bat = batRoom;
    bat2 = batRoom2;
}

void WumpusGame::placePits(){
    srand(time(NULL));  // rand() zal hierdoor steeds een andere selectie van getallen genereren
    bool validRoom = false;
    while(!validRoom){
        pitRoom = rand() % 20 + 1; // als room true is zet bat in random room van 1 tot 20
        if (pitRoom != wumpusRoom && pitRoom != startingPosition && pitRoom != batRoom && pitRoom != batRoom2){
            validRoom = true;
        }
    }
    validRoom = false;
    while(!validRoom){
        pitRoom2 = rand() % 20 + 1;
        if (pitRoom2 != pitRoom && pitRoom2 != wumpusRoom && pitRoom2 != startingPosition && pitRoom2 != batRoom && pitRoom2 != batRoom2){
            validRoom = true;
        }
    }
    pit = pitRoom;
    pit2 = pitRoom2;
}

bool WumpusGame::isRoomValid(int newRoom){
    vector<int> neighbour = read(newRoom);
    for(unsigned int i = 0; i < 3; i++){
            if(neighbour[i] == newRoom){
                return true;
            }
    }
    return false;
}  


bool WumpusGame::IsRoomAdjacent(int roomA, int roomB){
    vector<int> neighbour = read(roomA);
    for (int j = 0; j < 3; j++)
    {
        if(neighbour[j] == roomB){
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
    vector<int> neighbour = read(currentRoom);
    if(currentRoom == wumpusRoom){ //Als de wumpus je eet
        cout << "The Wumpus ate you!" << endl;
        cout << "You suck, loser" << endl;
        PlayAgain();
        
    } else if(currentRoom == batRoom || currentRoom == batRoom2){ // Als je in een batroom bent gekomen
        int roomBatsOver = currentRoom;;
        bool validNewBatRoom = false;
        bool isBatRoom = false;;
        cout << "A bat picked you up" << endl;
        while(!isBatRoom){
            currentRoom = Move(rand() % 20);
            if(currentRoom != batRoom && currentRoom != batRoom2){
                isBatRoom = true;
            } 
        }
        cout << "The bat moved you to room " << currentRoom << endl;
        InspectCurrentRoom();
        
        if(roomBatsOver == batRoom){
            while(!validNewBatRoom){
                batRoom = rand() % 19;
                if(batRoom != wumpusRoom && batRoom != currentRoom){
                    validNewBatRoom = true;
                }
            }
        } else{
            while(!validNewBatRoom){
                batRoom2 = rand() % 19;
                if(batRoom2 != wumpusRoom && batRoom2 != currentRoom){
                    validNewBatRoom = true;
                }
            }
        }
    }
    
    else if(currentRoom == pitRoom || currentRoom == pitRoom2){ //als je in een pitrooom komt
        cout << "Rip, you fell in a pit" << endl;
        cout << "You suck, loser" << endl;
        PlayAgain();
    } else{
        cout << "You are in room ";
        cout << currentRoom << endl;
        cout << wumpusRoom << endl;
        cout << batRoom << endl;
        cout << batRoom2 << endl;
        cout << pitRoom << endl;
        cout << pitRoom2 << endl;
        if(IsRoomAdjacent(currentRoom, wumpusRoom)){
            cout << "Something smells fishy " << endl;
        }
        if(IsRoomAdjacent(currentRoom, batRoom) || IsRoomAdjacent(currentRoom, batRoom2)){
            cout << "Bats are nearby " << endl;
        }
        if(IsRoomAdjacent(currentRoom, pitRoom) || IsRoomAdjacent(currentRoom, pitRoom2)){
            cout << "You feel a draft " << endl;
        }
        cout << "Tunnels lead to rooms " << endl;
        for (int j = 0; j < 3; j++)
        {
            cout << neighbour[j] << " ";
        }
            cout << endl;
    }
}

void WumpusGame::PlayAgain(){
    char antwoord;
    cout << "Would you like to play again? Enter Y/N, enter Y to play again.";
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
    placeBats();
    placePits();
    
    //vector<vector<int>> locations;
    //locations.push_back()
    
 
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
  vector<vector<int>> map = generateMap();
  write(map);
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
