#include "WumpusFunctions.h"

WumpusGame() {
    numRooms = 20;
}

vector<vector<int>> generateMap(){
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

void PlacePlayer() {
    startingPosition = rand() % 20 + 1;
    currentRoom = Move(startingPosition);
} 

void PlaceWumpus(){
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

void placeBats(){
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

void placePits(){
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