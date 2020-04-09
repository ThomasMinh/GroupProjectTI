/* bool isRoomValid(int newRoom){ //Checkt of de room wel goed is om te moven
    // Slaat de buurkamers van de huidige kamer.
    vector<int> neighbour = read(currentRoom);
    
    // Loopt door de buurkamers, als 1 gelijk is aan de gegeven kamer return true,
    // anders return false.
    for(unsigned int i = 0; i < 3; i++){
            if(neighbour[i] == newRoom){
                return true;
            }
    }
    return false;
}  

bool IsRoomAdjacent(int roomA, int roomB){ //Check om te kijken of de hazard naast je room is
    vector<int> neighbour = read(roomA); //leest de lijn(room) en pakt de 3 kamers in die lijn 
    for (int j = 0; j < 3; j++)
    {
        if(neighbour[j] == roomB){ //checkt of één van de kamers gelijk is aan de kamer van de hazard
          return true;
        }
    }
    return false;
}
 
 
bool neighbourNeighbour(int currentRoom, int coronaRoom){ //Deze functie is om de corona te ruiken
	vector<int> neighbours = read(currentRoom); // slaat de buurkamers op van de huidige kamer.
	vector<int> neighboursOfNeighbour = {}; // slaat de buurkamers op van de buurkamers van de currentroom.
    
	// Loop door de buurkamers van de huidige kamer.
	for(unsigned int i = 0; i < neighbours.size(); i++){
		// Als de buurkamer hetzelfde is als de coroona kamer, return true.
		if (neighbours[i] == coronaRoom){
			return true;
		}
		
		neighboursOfNeighbour = read(neighbours[i]); // sla de buurkamers van de huidige buurkamer op. 
		
		// Loop door de buurkamers van de huidige buurkamer.
		for(unsigned int j = 0; j < neighboursOfNeighbour.size(); j++){
			// Als de buurkamer hetzelfde is als de corona kamer, return true.	
			if (neighboursOfNeighbour[j] == coronaRoom){
				return true;
			}
		}
	}
	// Als de corona kamer niet gevonden is, return false.
	return false;
}
 
void InspectCurrentRoom() { //Inspecteerd in welke kamer je zit en of die ergens aan gelijk is
    vector<int> neighbour = read(currentRoom);
    if(currentRoom == coronaRoom){ //Als de corona je infecteert
        if(hasVent == true){    // checkt of je een fan hebt of niet
            cout << "You used the fan to blow the Corona away" << endl;
            hasVent = false;
            moveCorona();   // zo ja zet hij de hasVent weer naar false en voert hij moveCorona() uit voor een kans dat Corona naar een andere kamer gaat
            if(currentRoom == coronaRoom){  // checkt nog een keer of Corona uit de kamer is gegaan, zo niet dan ben je dood
                cout << "Oh no, The fan didn't work! you have been killed by the Coronavirus" << endl;
                tryCounter++;
                if(computerAlive){
                    PlayAgainComputer();
                } else{
                    PlayAgain();
                }
            } else{	// Corona is dan naar een andere kamer gemoved
                cout << "You managed to blow the Coronavirus away. The fan seems unusable now" << endl;
                InspectCurrentRoom();
            }
        } else{	// Corona heeft je gedood
            cout << "You have been killed by the Coronavirus" << endl;
            cout << "You suck, loser " << endl;
            tryCounter++;
            if(computerAlive){
                    PlayAgainComputer();
                } else{
                    PlayAgain();
                }
        }
    } 
    
    else if(currentRoom == policeRoom || currentRoom == policeRoom2){ // Als je in een batroom bent gekomen
        int roomPoliceOver = currentRoom;;
        bool validNewPoliceRoom = false;
        bool isPoliceRoom = false;;
        cout << "A police officer caught you" << endl;
        while(!isPoliceRoom){
            currentRoom = Move(rand() % 20 + 1);    //moved je naar een random kamer wat geen police room is
            if(currentRoom != policeRoom && currentRoom != policeRoom2){
                isPoliceRoom = true;
            } 
        }
        cout << "The police moved you to room " << currentRoom << endl;
        InspectCurrentRoom();
        
        if(roomPoliceOver == policeRoom){   //moved de police naar een random andere kamer
            while(!validNewPoliceRoom){
                policeRoom = rand() % 19 + 1;
                if(policeRoom != coronaRoom && policeRoom != currentRoom){
                    validNewPoliceRoom = true;
                }
            }
        } else{
            while(!validNewPoliceRoom){
                policeRoom2 = rand() % 19 + 1;
                if(policeRoom2 != coronaRoom && policeRoom2 != currentRoom){
                    validNewPoliceRoom = true;
                }
            }
        }
    }
    
    
    else if(currentRoom == qZoneRoom || currentRoom == qZoneRoom2){ //als je in een pitrooom komt
        cout << "Rip, you got quarantined" << endl;
        cout << "You suck, loser" << endl;
        tryCounter++;
        if(computerAlive){
            PlayAgainComputer();
        } else{
            PlayAgain();
        }
    } else{
        cout << endl;
        if(currentRoom == ventRoom){    // als je in de ventRoom komt pak je de fan en wordt hasVent true
            cout << "You found a fan! This may come in handy." << endl;
            hasVent = true;
        } 
        cout << "You are in room ";
        cout << currentRoom << endl;
        if(neighbourNeighbour(currentRoom, coronaRoom)){    //kijkt of je 2 of minder kamers bent verwijderd van de coronakamer
            cout << "My skin feels itchy " << endl;
            feelCorona = true;
        } else{
            feelCorona = false;
        }if(IsRoomAdjacent(currentRoom, policeRoom) || IsRoomAdjacent(currentRoom, policeRoom2)){   //kijkt of je 2 of minder kamers bent verwijderd van de policeroom
            cout << "You hear sirens nearby " << endl;
        }
        if(IsRoomAdjacent(currentRoom, qZoneRoom) || IsRoomAdjacent(currentRoom, qZoneRoom2)){  //kijkt of je 2 of minder kamers bent verwijderd van de quarantaine zone
            cout << "You can hear people coughing " << endl;
        }
        cout << "Tunnels lead to rooms " << endl;
        for (int j = 0; j < 3; j++) //Laat zien naar welke kamers je kan.
        {
            cout << neighbour[j] << " ";
        }
            cout << endl;
    }
}*/