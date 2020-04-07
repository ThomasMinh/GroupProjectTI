#include "WumpusFunctions.h"

int newRoom = 0;
int currentRoom = 0, startingPosition = 0 ;
int wumpusRoom = 0, wumpusStart = 0, bat1Start = 0, bat2Start = 0;
bool playerAlive = true, wumpusAlive = true;
int batRoom = 0, batRoom2 = 0, pitRoom = 0, pitRoom2 = 0;
int bat = 0, bat2 = 0, pit = 0, pit2 = 0;
int arrows = 5;
fstream WFile;
vector<vector<int>> map = generateMap();

void PlacePlayer() {
    startingPosition = rand() % 20 + 1; //random nummer wordt gegenereerd tussen 1-20
    currentRoom = Move(startingPosition); //speler wordt gemoved naar dat random nummer 
} 

void PlaceWumpus(){
    bool validRoom = false;
    while(!validRoom){ // maakt validroom true om ze in de rooms te plaatsen
        int randomRoom = rand() % 20 + 1; //genereerd random nummer 1-20
        if(randomRoom != startingPosition){ //checkt of hij niet gelijk is
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
        pitRoom = rand() % 20 + 1; // als room true is zet pit in random room van 1 tot 20
        if (pitRoom != wumpusRoom && pitRoom != startingPosition && pitRoom != batRoom && pitRoom != batRoom2){ //pitroom mag niet gelijk zijn aan wumpusroom, startingposition.
            validRoom = true;
        }
    }
    validRoom = false;
    while(!validRoom){ 
        pitRoom2 = rand() % 20 + 1;
        if (pitRoom2 != pitRoom && pitRoom2 != wumpusRoom && pitRoom2 != startingPosition && pitRoom2 != batRoom && pitRoom2 != batRoom2){ //pitroom2 mag niet gelijk zijn aan wumpusroom, startingposition. 
            validRoom = true;
        }
    }
    pit = pitRoom;
    pit2 = pitRoom2;
}

void write(vector<vector<int>> & numbers){
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
}

void PlayAgain(){
    char antwoord;
    cout << "Would you like to play again with the same map? Enter Y/N. if you want to quit, press Q" << endl;
    cin >> antwoord;
    if(antwoord == 'y' || antwoord == 'Y'){
        currentRoom = startingPosition;
        wumpusRoom = wumpusStart;
        batRoom = bat1Start;
        batRoom2 = bat2Start;
        InspectCurrentRoom();
    }else if(antwoord == 'q' || antwoord == 'Q'){
        StartGame();
    } else {
        srand(time(NULL));  // rand() zal hierdoor steeds een andere selectie van getallen genereren
        vector<vector<int>> map = generateMap();
        PlacePlayer();
        PlaceWumpus();
        placeBats();
        placePits();
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

void moveWumpus(){
	int randomNumber = rand() % 4 + 1;
	vector <int> naast = read(wumpusRoom);
	if(randomNumber == 1){
		wumpusRoom = wumpusRoom;
	}
	else if(randomNumber == 2) {
		wumpusRoom = naast[0];
	}
	else if(randomNumber == 3) {
		wumpusRoom = naast[1];
	}
	else if(randomNumber == 4) {
		wumpusRoom = naast[2];
	}
	write(map);
}

int Move(int newRoom){
    return newRoom;
}

void PlayGame(){
    srand (time(NULL));
    int choice;
    bool validChoice = false;
    vector<vector<int>> map = generateMap();
    
    srand(time(NULL));  // rand() zal hierdoor steeds een andere selectie van getallen genereren
    PlacePlayer();
    PlaceWumpus();
    placeBats();
    placePits();
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

