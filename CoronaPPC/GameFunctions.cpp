#include "CoronaFunctions.h"

int newRoom = 0;
int currentRoom = 0, startingPosition = 0 ;
int coronaRoom = 0, coronaStart = 0, police1Start = 0, police2Start = 0, ventStart = 0;
bool playerAlive = true, coronaAlive = true, computerAlive = true; //kan playyer in apart functie
int policeRoom = 0, policeRoom2 = 0, qZoneRoom = 0, qZoneRoom2 = 0, ventRoom = 0;
int police = 0, police2 = 0, qZone = 0, qZone2 = 0, vent = 0;
int sprays = 5, turnsFelt = 0, counter = 0, tryCounter = 1;
bool hasVent = false, feelCorona = false;
fstream WFile;
vector<vector<int>> map = generateMap();

void PlacePlayer() {
    startingPosition = rand() % 20 + 1; //random nummer wordt gegenereerd tussen 1-20
    currentRoom = Move(startingPosition); //speler wordt gemoved naar dat random nummer 
} 

void PlaceCorona(){
    bool validRoom = false;
    while(!validRoom){ // maakt validroom true om ze in de rooms te plaatsen
        int randomRoom = rand() % 20 + 1; //genereerd random nummer 1-20
        if(randomRoom != startingPosition){ //checkt of hij niet gelijk is
            validRoom = true;
            coronaRoom = randomRoom;
            coronaStart = coronaRoom;
        }
    }
}

void placePolice(){
    bool validRoom = false; // zodat hij niet genereert waar de player staat
    while (!validRoom){
        policeRoom = rand() % 20 + 1; // als room true is zet bat in random room van 1 tot 20
        if(policeRoom != policeRoom2 && policeRoom != startingPosition && policeRoom != coronaRoom){ // als batRoom niet hetzelfde is als waar de wumpus is, is de room valid
            validRoom = true;
        }
    }
    validRoom = false;
    while(!validRoom){
        policeRoom2 = rand() % 20 + 1;
        if (policeRoom2 != policeRoom && policeRoom2 != startingPosition && policeRoom2 != coronaRoom){
            validRoom = true;
        }
    }
    police = policeRoom;
    police2 = policeRoom2;
}

void placeQZones(){
    bool validRoom = false;
    while(!validRoom){
        qZoneRoom = rand() % 20 + 1; // als room true is zet pit in random room van 1 tot 20
        if (qZoneRoom != coronaRoom && qZoneRoom != startingPosition && qZoneRoom != policeRoom && qZoneRoom != policeRoom2){ //pitroom mag niet gelijk zijn aan coronaRoom, startingposition.
            validRoom = true;
        }
    }
    validRoom = false;
    while(!validRoom){ 
        qZoneRoom2 = rand() % 20 + 1;
        if (qZoneRoom2 != qZoneRoom && qZoneRoom2 != coronaRoom && qZoneRoom2 != startingPosition && qZoneRoom2 != policeRoom && qZoneRoom2 != policeRoom2){ //pitroom2 mag niet gelijk zijn aan coronaRoom, startingposition. 
            validRoom = true;
        }
    }
    qZone = qZoneRoom;
    qZone2 = qZoneRoom2;
}

void placeVentilator(){
	bool validRoom = false;
	while(!validRoom){
        ventRoom = rand() % 20 + 1;
		 if (ventRoom != coronaRoom && ventRoom != startingPosition && ventRoom != policeRoom && ventRoom != policeRoom2 && ventRoom != qZoneRoom && ventRoom != qZoneRoom2){
            validRoom = true;
		 }
	}
	vent = ventRoom;
}

void write(vector<vector<int>> & numbers){
	ofstream WFile("map.txt");

	for(unsigned int i=0; i<numbers.size();i++){
		for(unsigned int j=0; j<numbers[i].size();j++){
			WFile << numbers[i][j] << " ";
		}
        WFile << "\n";
	}
    WFile << "corona is in room = " << coronaRoom << "\n";
    WFile << "PoliceRoom1 is room = " << policeRoom << "\n";
    WFile << "PoliceRoom2 is room = " << policeRoom2 << "\n";
    WFile << "QuarantineZone1 is room = " << qZoneRoom << "\n";
    WFile << "QuarantineZone2 is room = " << qZoneRoom2 << "\n";
    WFile << "The fan is in room = " << ventRoom << "\n";
 
	WFile.close();
}

vector<int> read(int roomID){
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
    if(currentRoom == coronaRoom){ //Als de corona je infecteert
        if(hasVent == true){
            cout << "You used the fan to blow the Corona away" << endl;
            hasVent = false;
            moveCorona();
            if(currentRoom == coronaRoom){
                cout << "Oh no, The fan didn't work! you have been killed by the Coronavirus" << endl;
                tryCounter++;
                if(computerAlive){
                    PlayAgainComputer();
                } else{
                    PlayAgain();
                }
            } else{
                cout << "You managed to blow the Coronavirus away. The fan seems unusable now" << endl;
                InspectCurrentRoom();
            }
        } else{
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
            currentRoom = Move(rand() % 20);
            if(currentRoom != policeRoom && currentRoom != policeRoom2){
                isPoliceRoom = true;
            } 
        }
        cout << "The police moved you to room " << currentRoom << endl;
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
        if(currentRoom == ventRoom){
            cout << "You found a fan! This may come in handy." << endl;
            hasVent = true;
        } 
        cout << "You are in room ";
        cout << currentRoom << endl;
        if(neighbourNeighbour(currentRoom, coronaRoom)){
            cout << "My skin feels itchy " << endl;
			feelCorona = true;
        } else{
			feelCorona = false;
        }if(IsRoomAdjacent(currentRoom, policeRoom) || IsRoomAdjacent(currentRoom, policeRoom2)){
            cout << "You hear sirens nearby " << endl;
        }
        if(IsRoomAdjacent(currentRoom, qZoneRoom) || IsRoomAdjacent(currentRoom, qZoneRoom2)){
            cout << "You can hear people coughing " << endl;
        }
        cout << "Tunnels lead to rooms " << endl;
        for (int j = 0; j < 3; j++)
        {
            cout << neighbour[j] << " ";
        }
            cout << endl;
    }
}

void PlayAgain(){
    sprays = 5;
    counter = 0;
    char antwoord;
    cout << "Would you like to play again with the same map? Enter Y/N. if you want to quit, press Q" << endl;
    cin >> antwoord;
    if(antwoord == 'y' || antwoord == 'Y'){
        currentRoom = startingPosition;
        coronaRoom = coronaStart;
        policeRoom = police1Start;
        policeRoom2 = police2Start;
        ventRoom = ventStart;
        
        InspectCurrentRoom();
    }else if(antwoord == 'q' || antwoord == 'Q'){
        StartGame();
    } else {
        srand(time(NULL));  // rand() zal hierdoor steeds een andere selectie van getallen genereren
        vector<vector<int>> map = generateMap();
        PlacePlayer();
        PlaceCorona();
        placePolice();
        placeQZones();
        placeVentilator();
        write(map);
        InspectCurrentRoom();
    }
    
}

void PerformAction(int cmd) {
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
            if (sprays > 0){ //kijkt of user nog sprays heeft, zo ja dan kan de user door spelen
                cout << "Which room? " << endl;
                try{
                    cin >> newRoom;
                    if (isRoomValid(newRoom)){ // kijkt of de nieuwe room die de user als input gegeven heeft valid is
                        sprays--;
                        if (newRoom == coronaRoom){
                            cout << "Splashhhhh!" << endl;
                            cout << "The Coronavirus has been exterminated" << endl;
                            cout << "Congratulations!! You win!!" << endl;
                            cout << "It took you: " << counter << " turns to win." << endl;
                            coronaAlive = false; //Corona is exterminated 
                            PlayGame();
                        } 
                        else{
                            cout << "Oh no!!, you missed the Corona!!" << endl;
                            cout << "The Corona flew to another room " << endl;
                            moveCorona();
                            if(coronaRoom == currentRoom){
                                cout << "The Corona flew to your room" << endl;
                                cout << "YOU HAVE BEEN INFECTED, now you're dead. You suck, loser" << endl;
                                PlayAgain();
                                } 
                            } InspectCurrentRoom();
                        }
                } catch (...){
                    cout << "Not valid to shoot there" << endl;
                }
            } else{
                cout << "No sprays for you" << endl;
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

void moveCorona(){
	int randomNumber = rand() % 4 + 1;
	vector <int> naast = read(coronaRoom);
	if(randomNumber == 1){
		coronaRoom = coronaRoom;
	}
	else if(randomNumber == 2) {
		coronaRoom = naast[0];
	}
	else if(randomNumber == 3) {
		coronaRoom = naast[1];
	}
	else if(randomNumber == 4) {
		coronaRoom = naast[2];
	}
	write(map);
}

int Move(int newRoom){
    return newRoom;
    counter++;
}

void PlayGame(){
    computerAlive = false;
    int choice;
    bool validChoice = false;
    vector<vector<int>> map = generateMap();
    PlacePlayer();
    PlaceCorona();
    placePolice();
    placeQZones();
    placeVentilator();
    write(map);
    
    InspectCurrentRoom();
 
    while (playerAlive)
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

void PlayAgainComputer(){
    cout << "Would you like to play again with the same map? Enter Y/N. if you want to quit, press Q" << endl;
    cout << "Y " << endl; 
    currentRoom = startingPosition;
    coronaRoom = coronaStart;
    policeRoom = police1Start;
    policeRoom2 = police2Start;
    ventRoom = ventStart;
    sprays = 5;
    counter = 0;
    InspectCurrentRoom();
}

void moveComputer(){
    cout << "1" << endl;
    int roomChoice = 0;
    vector<int> neighbourRooms = read(currentRoom); //leest alle buurkamers die er zijn
    int randNumber = rand() % 3; //genereert een random nummer tussen 0 en 2
    
    cout << "Which room? ";
    roomChoice = neighbourRooms[randNumber]; // kiest een kamer van 1 van de buurkamers
    cout << roomChoice << endl; //de computer laat zijn keuze zien 
    currentRoom = Move(roomChoice);
    InspectCurrentRoom();
}

void PlayGameComputer(){
    playerAlive = false;
    sprays = 5;
    tryCounter = 1;
    vector<vector<int>> map = generateMap();

    PlacePlayer();
    PlaceCorona();
    placePolice();
    placeQZones();
    write(map);
    
    InspectCurrentRoom();
 
    while (computerAlive){
        cout << "Enter an action choice." << endl;
        cout << "1) Move" << endl;
        cout << "2) Shoot?" << endl;
        cout << ">>> ";
 
        cout << "Please make a selection: ";
        
        
        // Als de hint dat de corona dichtbij is gegeven is, verhoog het aantal beurten dat de hint gegeven is met 1.
        if (feelCorona == true){
            turnsFelt++;
        }
        else{
		turnsFelt = 0;
        }
        counter++;
        cout << "Sprays " << sprays << endl;
        // Als de corona vaker dan 1 keer geroken is en er nog sprays over zijn, spray in 1 van de buurkamers.
        if (turnsFelt > 1 && sprays > 0){
            cout << "2" << endl;
            sprays--;
            vector<int> neighbours = read(currentRoom);
            int choice = rand() % 3;
            cout << "Which room? " << endl;
            cout << neighbours[choice] << endl;
		
            // Als het de kamer was met de corona, dan heeft de computer gewonnen.
            if(neighbours[choice] == coronaRoom){
                cout << "Splashhhhh!" << endl;
                cout << "The Coronavirus has been exterminated!" << endl;
                cout << "Congratulations!! You win!!" << endl;
                cout << "It took the computer: " << counter << " turns " << endl;
                cout << "and " << tryCounter << " tries to win." << endl;
                
                cout << endl;
                coronaAlive = false; // Corona is dood
                StartGame();
            }
            // Als het niet de goede kamer was beweegt de wumpus.
            else{
                cout << "Oh no!!, you missed the Corona!!" << endl;
                cout << "The Corona flew to another room " << endl;
                turnsFelt = 0;
                moveCorona();
                    // Als de corona naar de kamer dat de computer zat bewoog, dan heeft de computer verloren.
                    if(coronaRoom == currentRoom){
                        cout << "The Corona flew to your room" << endl;
                        cout << "YOU ARE INFECTED, now you're dead. You suck, loser" << endl;
                        PlayAgainComputer();
                    }
                    else{
                        // Als het spel nog niet voorbij is, ga naar de volgende beurt.
                        InspectCurrentRoom();
                    }
            }
        } else{
            moveComputer();
        }
    }
}