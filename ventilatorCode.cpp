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
      int wumpusRoom, wumpusStart, bat1Start, bat2Start;
      bool playerAlive, wumpusAlive, validRoom, hasVent;
      int batRoom, batRoom2, pitRoom, pitRoom2, ventRoom;
      int bat, bat2, pit, pit2;
      int arrows;
      fstream WFile;
      vector<vector<int>> map = generateMap();

      vector<vector<int>> generateMap();
      void PlayGame();
      void write(vector<vector<int>> & numbers);
      vector<int> read(int currentroom);
      void PlacePlayer();
      void PlaceWumpus();
      void placeBats();
      void placePits();
      bool IsRoomAdjacent(int, int);
      int Move(int);
      void InspectCurrentRoom();
      void PerformAction(int);
      bool isRoomValid(int);
      void PlayAgain();
      bool neighbourNeighbour(int, int ); 
      void moveWumpus();
	  void ventilator();
      
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
    WFile << "Wumpus is in room = " << wumpusRoom << "\n";
    WFile << "batroom1 is room = " << batRoom << "\n";
    WFile << "batroom2 is room = " << batRoom2 << "\n";
    WFile << "pitroom1 is room = " << pitRoom << "\n";
    WFile << "pitroom2 is room = " << pitRoom2 << "\n";
	WFile << "ventRoom is room = " << ventRoom << "\n";
 
	WFile.close();
}

vector<int> WumpusGame::read(int roomID){
    string Text = "";
    int number;
	int line = 0;
	int regel = roomID;
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
        RFile.close();
        }
    return rooms;
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
    vector<int> neighbour = read(currentRoom);
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

void WumpusGame::moveWumpus(){
	int o = rand() % 4 + 1;
	vector <int> naast = read(wumpusRoom);
	if(o == 1){
		wumpusRoom = wumpusRoom;
	}
	else if(o == 2) {
		wumpusRoom = naast[0];
	}
	else if(o == 3) {
		wumpusRoom = naast[1];
	}
	else if(o == 4) {
		wumpusRoom = naast[2];
	}
	write(map);
 }
 
bool WumpusGame::neighbourNeighbour(int currentRoom, int wumpusRoom){ //Deze functie is om de de wumpus te ruiken
	vector<int> neighbours = read(currentRoom);
	vector<int> neighboursOfNeighbour = {};
	
	for(unsigned int i = 0; i < neighbours.size(); i++){
		if (neighbours[i] == wumpusRoom){
			return true;
		}
		
		neighboursOfNeighbour = read(neighbours[i]);
		for(unsigned int j = 0; j < neighboursOfNeighbour.size(); j++){
			if (neighboursOfNeighbour[j] == wumpusRoom){
				return true;
			}
		}
	}
	return false;
}
 
void WumpusGame::InspectCurrentRoom() {
    srand (time(NULL));
    vector<int> neighbour = read(currentRoom);
    if(currentRoom == wumpusRoom){ //Als de wumpus je eet
		if(hasVent == true){
			cout << "You used the fan to blow away the Coronavirus." << "\n";
			hasVent = false;
			moveWumpus();
			if(currentRoom == wumpusRoom){
				cout << "Oh no, The fan didn't work!" << "\n" << "you have been killed by the Coronavirus" << "\n";
				PlayAgain();
			}	else{
					cout << "You managed to blow the Coronavirus away" << "\n" << "The fan seems unusable now" << "\n";
				}
			
		}	else{
				cout << "The Wumpus ate you!" << endl;
				cout << "You suck, loser" << endl;
				PlayAgain();
			}
        
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
        } else if(currentRoom == ventRoom){
			cout << "You found a fan!" << "\n" << "This may come handy.";
			hasVent = true;
		}
		
		else{
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
        if(neighbourNeighbour(currentRoom, wumpusRoom)){
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
    cout << "Would you like to play again with the same map? Enter Y/N. if you want to quit, press Q" << endl;
    cin >> antwoord;
	hasVent = false;
    if(antwoord == 'y' || antwoord == 'Y'){
        currentRoom = startingPosition;
        wumpusRoom = wumpusStart;
        batRoom = bat1Start;
        batRoom2 = bat2Start;
        InspectCurrentRoom();
    }else if(antwoord == 'q' || antwoord == 'Q'){
        StartGame();
    } else {
        vector<vector<int>> map = generateMap();
        PlacePlayer();
        PlaceWumpus();
        placeBats();
        placePits();
        write(map);
        InspectCurrentRoom();
    }
    
}

void WumpusGame::PerformAction(int cmd) {
    int newRoom;
    string line;
    ifstream WFile("map.txt");
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
            if (arrows > 0){ //kijkt of user nog arrows heeft, zo ja dan kan de user door spelen
                cout << "Which room? " << endl;
                try{
                    cin >> newRoom;
                    if (isRoomValid(newRoom)){ // kijkt of de nieuwe room die de user als input gegeven heeft valid is
                        arrows--;
                        if (newRoom == wumpusRoom){
                            cout << "Splashhhhh!" << endl;
                            cout << "The Wumpus is dead. You killed him!" << endl;
                            cout << "Congratulations!! You win!!" << endl;
                            wumpusAlive = false; //Wumpus is dood
                            PlayGame();
                        } 
                        else{
                            cout << "Oh no!!, you missed the Wumpus!!" << endl;
                            cout << "The Wumpus moved " << endl;
                            moveWumpus();
                            if(wumpusRoom == currentRoom){
                                cout << "The Wumpus moved to your room" << endl;
                                cout << "HE ATE YOU, now you're dead. You suck, loser" << endl;
                                PlayAgain();
                                } 
                            } InspectCurrentRoom();
                        }
                } catch (...){
                    cout << "Not valid to shoot there" << endl;
                }
            } else{
                cout << "No arrows for you" << endl;
            }
            break;
            
        case 3:
            cout << "Quitting the current game." << endl;
            if(WFile.is_open()){
                while(getline(WFile, line)){
                    cout << line << "\n";
                }
                WFile.close();
            }
            playerAlive = false;
            break;
        default:
            cout << "You cannot do that. You can move, shoot or quit." << endl;
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
    write(map);

    playerAlive = true;
    wumpusAlive = true;
    arrows = 5;
    
    InspectCurrentRoom();
 
    while (playerAlive)
    {
        cout << "Enter an action choice." << endl;
        cout << "1) Move" << endl;
        cout << "2) Shoot?" << endl;
        cout << "3) Quit" << endl;
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
        
        do{
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
 
void WumpusGame::ventilator(){
	ventRoom = rand() % 20 + 1;
	validRoom = false;
	hasVent = false;
	while(!validRoom){
		 if (ventRoom != wumpusRoom && ventRoom != startingPosition && ventRoom != batRoom && ventRoom != batRoom2 && ventRoom != pitRoom && ventRoom != pitRoom2){
            validRoom = true;
		 }
	}
	
}
 
int main() {
    WumpusGame game;
    game.StartGame();
}