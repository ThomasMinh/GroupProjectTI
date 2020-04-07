/* bool isRoomValid(int newRoom){
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
 
 
bool neighbourNeighbour(int currentRoom, int coronaRoom){ //Deze functie is om de de wumpus te ruiken
	vector<int> neighbours = read(currentRoom);
	vector<int> neighboursOfNeighbour = {};
	
	for(unsigned int i = 0; i < neighbours.size(); i++){
		if (neighbours[i] == coronaRoom){
			return true;
		}
		
		neighboursOfNeighbour = read(neighbours[i]);
		for(unsigned int j = 0; j < neighboursOfNeighbour.size(); j++){
			if (neighboursOfNeighbour[j] == coronaRoom){
				return true;
			}
		}
	}
	return false;
}
 
void InspectCurrentRoom() {
    vector<int> neighbour = read(currentRoom);
    if(currentRoom == coronaRoom){ //Als de wumpus je eet
        
        cout << "The Wumpus ate you!" << endl;
        cout << "You suck, loser" << endl;
        PlayAgain();
        
    } else if(currentRoom == policeRoom || currentRoom == policeRoom2){ // Als je in een batroom bent gekomen
        int roomPoliceOver = currentRoom;;
        bool validNewPoliceRoom = false;
        bool isPoliceRoom = false;;
        cout << "A bat picked you up" << endl;
        while(!isPoliceRoom){
            currentRoom = Move(rand() % 20);
            if(currentRoom != policeRoom && currentRoom != policeRoom2){
                isPoliceRoom = true;
            } 
        }
        cout << "The bat moved you to room " << currentRoom << endl;
        InspectCurrentRoom();
        
        if(roomPoliceOver == policeRoom){
            while(!validNewPoliceRoom){
                policeRoom = rand() % 19;
                if(policeRoom != coronaRoom && policeRoom != currentRoom){
                    validNewPoliceRoom = true;
                }
            }
        } else{
            while(!validNewPoliceRoom){
                policeRoom2 = rand() % 19;
                if(policeRoom2 != coronaRoom && policeRoom2 != currentRoom){
                    validNewPoliceRoom = true;
                }
            }
        }
    }
    
    else if(currentRoom == qZoneRoom || currentRoom == qZoneRoom2){ //als je in een pitrooom komt
        cout << "Rip, you fell in a pit" << endl;
        cout << "You suck, loser" << endl;
        PlayAgain();
    } else{
        cout << "You are in room ";
        cout << currentRoom << endl;
        if(neighbourNeighbour(currentRoom, coronaRoom)){
            cout << "Something smells fishy " << endl;
        }
        if(IsRoomAdjacent(currentRoom, policeRoom) || IsRoomAdjacent(currentRoom, policeRoom2)){
            cout << "Bats are nearby " << endl;
        }
        if(IsRoomAdjacent(currentRoom, qZoneRoom) || IsRoomAdjacent(currentRoom, qZoneRoom2)){
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