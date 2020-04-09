#include "CoronaFunctions.h"
//Alle globale functies
int newRoom = 0;
int currentRoom = 0, startingPosition = 0 ;
int coronaRoom = 0, coronaStart = 0;
bool playerAlive = true, coronaAlive = true, computerAlive = true; 
int policeRoom = 0, policeRoom2 = 0, qZoneRoom = 0, qZoneRoom2 = 0, ventRoom = 0; //Alle 
int police1Start = 0, police2Start = 0, qZone1Start = 0, qZone2Start = 0, ventStart = 0;
int sprays = 5, turnsFelt = 0, counter = 0, tryCounter = 1;
bool hasVent = false, feelCorona = false;
fstream WFile;
vector<vector<int>> map = generateMap();

void PlacePlayer() { //plaatst de speler
    startingPosition = rand() % 20 + 1; //random nummer wordt gegenereerd tussen 1-20
    currentRoom = Move(startingPosition); //speler wordt gemoved naar dat random nummer 
} 

void PlaceCorona(){ //plaatst the corona die je moet killen
    bool validRoom = false;
    while(!validRoom){ // maakt validroom true om ze in de rooms te plaatsen
        int randomRoom = rand() % 20 + 1; //genereerd random nummer 1-20
        if(randomRoom != startingPosition){ //checkt of hij niet gelijk is aan de start positie van de speler
            validRoom = true;
            coronaRoom = randomRoom; //het randomnummer wordt gegeven aan de corona room
            coronaStart = coronaRoom; //om de start positie vast te stellen voor als de game weer wordt gespeeld met dezelfde map 
        }
    }
}

void placePolice(){ //plaatst de police officers die je kunnen moven
    bool validRoom = false; 
    while (!validRoom){
        policeRoom = rand() % 20 + 1; // als room true is zet police officer in random room van 1 tot 20
        if(policeRoom != policeRoom2 && policeRoom != startingPosition && policeRoom != coronaRoom){ // als policeRoom niet hetzelfde is als waar de corona, speler en tweede police officer is, is de room valid
            validRoom = true;
        }
    }
    validRoom = false;
    while(!validRoom){ // zelfde als voor de eerste police room
        policeRoom2 = rand() % 20 + 1;
        if (policeRoom2 != policeRoom && policeRoom2 != startingPosition && policeRoom2 != coronaRoom){
            validRoom = true;
        }
    }
    police1Start = policeRoom; //om de start posities vast te stellen voor als de game weer wordt gespeeld met dezelfde map 
    police2Start = policeRoom2;
}

void placeQZones(){ //plaatst de Quarantaine zones
    bool validRoom = false;
    while(!validRoom){
        qZoneRoom = rand() % 20 + 1; // als room true is zet pit in random room van 1 tot 20
        if (qZoneRoom != coronaRoom && qZoneRoom != startingPosition && qZoneRoom != policeRoom && qZoneRoom != policeRoom2){ //qZoneroom mag niet gelijk zijn aan coronaRoom, startingposition.
            validRoom = true;
        }
    }
    validRoom = false;
    while(!validRoom){ 
        qZoneRoom2 = rand() % 20 + 1;
        if (qZoneRoom2 != qZoneRoom && qZoneRoom2 != coronaRoom && qZoneRoom2 != startingPosition && qZoneRoom2 != policeRoom && qZoneRoom2 != policeRoom2){ //qZoneroom2 mag niet gelijk zijn aan coronaRoom, startingposition. 
            validRoom = true;
        }
    }
    qZone1Start = qZoneRoom; //om de start posities vast te stellen voor als de game weer wordt gespeeld met dezelfde map 
    qZone2Start = qZoneRoom2;
}

void placeVentilator(){    //deze functie plaatste de ventilator in een random kamer
    bool validRoom = false;
    while(!validRoom){
        ventRoom = rand() % 20 + 1;    //geeft de ventRoom een random kamer tussen 1 en 20
         if (ventRoom != coronaRoom && ventRoom != startingPosition && ventRoom != policeRoom && ventRoom != policeRoom2 && ventRoom != qZoneRoom && ventRoom != qZoneRoom2){    
            validRoom = true; //als de gegeven kamer niet overeen komt met een van de andere speciale kamers wordt hij toegewezen tot ventroom
         }
    }
    ventStart = ventRoom;
}

void write(vector<vector<int>> & numbers){ //schrijft de map en hazards naar map.txt
	ofstream WFile("map.txt");

	for(unsigned int i=0; i<numbers.size();i++){ // Gaat elke waarde in de vector vector int langs
		for(unsigned int j=0; j<numbers[i].size();j++){
			WFile << numbers[i][j] << " "; // Write alle buurkamers per regel bij elkaar naar map.txt
		}
        WFile << "\n";
	}
    WFile << "corona is in room = " << coronaRoom << "\n"; // Laat zien in welke kamers alle hazards zitten
    WFile << "PoliceRoom1 is room = " << policeRoom << "\n";
    WFile << "PoliceRoom2 is room = " << policeRoom2 << "\n";
    WFile << "QuarantineZone1 is room = " << qZoneRoom << "\n";
    WFile << "QuarantineZone2 is room = " << qZoneRoom2 << "\n";
    WFile << "The fan is in room = " << ventRoom << "\n";
 
	WFile.close();
}

vector<int> read(int roomID){ // Read de buurkamers van de gegeven kamer vanuit de map.txt
    string Text = "";
    int number;
	int line = 0;
	int regel = roomID;
    vector<int> rooms;
	ifstream RFile("map.txt");

	while (line != regel && getline(RFile, Text)) { // Haalt de lines uit de map.txt bestand en Telt door tot de regel van de gegeven kamer
		line++;
	}
	if(line == regel){ // voegt dan de buurkamers toe aan rooms zodra de juiste regel is bereikt
        stringstream iss(Text); //Om een string om te kunnen zetten naar een vector int
        while(iss >> number){
            rooms.push_back(number);
        }
        RFile.close();
        }
    return rooms; //return de vector int van buurkamers
}

bool isRoomValid(int newRoom){ //Checkt of de room wel goed is om te moven
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
}

void PlayAgain(){ //Als je dood gaat krijg je de optie om opnieuw te spelen
    sprays = 5; //je sprays reseten naar 5
    counter = 0; //counter voor de turns weer opnieuw zetten op 0
    char antwoord;
    cout << "Would you like to play again with the same map? Enter Y/N. if you want to quit, press Q" << endl;
    cin >> antwoord; 
    if(antwoord == 'y' || antwoord == 'Y'){ //Als je met dezelfde map wilt spelen worden alle startingposition weer gepakt 
        currentRoom = startingPosition; //en de rooms krijgen het nummer van de position die als eerst werd gemaakt.
        coronaRoom = coronaStart;
        policeRoom = police1Start;
        policeRoom2 = police2Start;
        ventRoom = ventStart;
        
        InspectCurrentRoom();
    }else if(antwoord == 'q' || antwoord == 'Q'){ //Weer terug naar main menu als je q invoert
        StartGame();
    } else {
        srand(time(NULL));  // rand() zal hierdoor steeds een andere selectie van getallen genereren
        vector<vector<int>> map = generateMap(); //De hele map wordt weer opnieuw gegenereert met nieuwe spawn locaties
        PlacePlayer();
        PlaceCorona();
        placePolice();
        placeQZones();
        placeVentilator();
        write(map);
        InspectCurrentRoom();
    }
    
}

void PerformAction(int cmd) { //om de te schieten, moven of quitten
    string line;
    ifstream WFile("map.txt");
    switch (cmd)
    {
 
        case 1: //moven naar een nieuwe room
            cout << "Which room? " << endl;
            try
            {
                cin >> newRoom;
                if (isRoomValid(newRoom)) //checken of het getal opgegeven wel geldig is
                {
                    currentRoom = Move(newRoom);
                    InspectCurrentRoom(); //checken waar je nu bent
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
            
            case 2: //Spray schieten
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
                            cout << endl;
                            coronaAlive = false; //Corona is exterminated 
                            StartGame(); //weer terug naar de main menu
                        } 
                        else{
                            cout << "Oh no!!, you missed the Corona!!" << endl;
                            cout << "The Corona flew to another room " << endl;
                            moveCorona(); //move corona naar zelfde of buurkamer van de corona
                            if(coronaRoom == currentRoom){
                                cout << "The Corona flew to your room" << endl;
                                cout << "YOU HAVE BEEN INFECTED, now you're dead. You suck, loser" << endl;
                                PlayAgain(); //Als de corona naar jou kamer is gevlogen, ben je dood en krijg je weer de optie om opnieuw te spelen
                                } 
                            } InspectCurrentRoom();
                        }
                } catch (...){ //als er geen gelde kamer is gegeven
                    cout << "Not valid to shoot there" << endl;
                }
            } else{
                cout << "No sprays for you" << endl;
            }
            break;
            
        case 3: //Quit de game en teruggaan naar de main menu 
            cout << "Quitting the current game." << endl;
            if(WFile.is_open()){ //check of de map.txt open is
                while(getline(WFile, line)){ //lees alle lines van de files
                    cout << line << "\n"; //cout alle lines die in de file staan
                }
                WFile.close(); //close de map.txt
            }
            playerAlive = false;
            break;
        default: //voor als er niks voor gegeven, dus als standaard.
            cout << "You cannot do that. You can move, shoot or quit." << endl;
            break;
    }
}

void moveCorona(){ // Zorgt ervoor dat er een kans is dat het coronavirus naar een buurkamer verplaatst als er mis is geschoten
	int randomNumber = rand() % 4 + 1; // random nummer genereren tussen 1 en 4;
	vector <int> naast = read(coronaRoom);
	if(randomNumber == 1){ //alle if's om het coronavirus te moven. Als het random getal 1 is blijft die in dezelfde kamer, bij 2 naar buurkamer 1 etc.
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
	write(map); //write functie aanroepen. Zet alles weer in de file met de veranderde kamer van het coronavirus
}

int Move(int newRoom){ //Move functie voor de speler een nieuwe room kiest om in te gaan.
    return newRoom;
}

void PlayGame(){ //Alles wordt geplaatst en geeft de opties
    computerAlive = false;    //als je voor playgame kiest is player alive en gaat computeralive naar false
	playerAlive = true;
    int choice;
    bool validChoice = false;
    vector<vector<int>> map = generateMap(); //alles wordt gegenereerd
    PlacePlayer();
    PlaceCorona();
    placePolice();
    placeQZones();
    placeVentilator();
    write(map); //schijf map naar map.txt

    InspectCurrentRoom();
 
    while (playerAlive)
    {
        cout << "Enter an action choice." << endl;  //laat opties zien
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
                cin >> choice;    //vraagt om jouw keuze
                switch (choice)
                {
                    case 1:    //voert de action uit gebasseerd op je keuze
                        PerformAction(choice);
                        break;
                    case 2:
                        PerformAction(choice);
                        break;
                    case 3:
                        PerformAction(choice);
                        break;
                    default:
                        validChoice = false;    //geeft error als je niet een van de 3 opties geeft
                        cout << "Invalid choice. Please try again." << endl;
                        cin.clear();
                        cin.ignore(10000, '\n');
                        break;
                }
            }
            catch (...) //checkt of er wel een goeie input is gegeven 
            {
                validChoice = false;
                cout << "Invalid choice. Please try again." << endl;
                cin.clear();
                cin.ignore(10000, '\n');
            }

        } while (validChoice == false);
    }
}

void PlayAgainComputer(){ //Play again voor de computerspeler
    cout << "Would you like to play again with the same map? Enter Y/N. if you want to quit, press Q" << endl;
    cout << "Y " << endl; //Computer speelt altijd door tot die gewonnen heeft
    currentRoom = startingPosition;
    coronaRoom = coronaStart;
    policeRoom = police1Start;
    policeRoom2 = police2Start;
    ventRoom = ventStart;
    sprays = 5;
    turnsFelt = 0;
    InspectCurrentRoom(); //checkt waar de computer is
}

void moveComputer(){ //move computer
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

void PlayGameComputer(){ //de AI gaat spelen
    playerAlive = false; //zet de playerAlive op false voor de playagain functies
	computerAlive = true;
    sprays = 5;
    tryCounter = 1; //tellen hoe vaak de AI de game heeft gespeeld met dezelfde configuratie
    counter = 0;
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
				computerAlive = false;
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
