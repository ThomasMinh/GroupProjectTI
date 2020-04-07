/*#include "WumpusFunctions.h"

bool isRoomValid(int newRoom){
    vector<int> neighbour = read(currentRoom);
    for(unsigned int i = 0; i < 3; i++){
            if(neighbour[i] == newRoom){
                return true;
            }
    }
    return false;
}  


bool IsRoomAdjacent(int roomA, int roomB){
    vector<int> neighbour = read(roomA);
    for (int j = 0; j < 3; j++)
    {
        if(neighbour[j] == roomB){
          return true;
        }
    }
    return false;
}
 
 
bool neighbourNeighbour(int currentRoom, int wumpusRoom){ //Deze functie is om de de wumpus te ruiken
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
 
void InspectCurrentRoom() {
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
}*/
