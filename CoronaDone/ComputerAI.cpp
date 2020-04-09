/*void PlayAgainComputer(){ //Play again voor de computerspeler
    cout << "Would you like to play again with the same map? Enter Y/N. if you want to quit, press Q" << endl;
    cout << "Y " << endl; //Computer speelt altijd door tot die gewonnen heeft
    currentRoom = startingPosition;
    coronaRoom = coronaStart;
    policeRoom = police1Start;
    policeRoom2 = police2Start;
    ventRoom = ventStart;
    sprays = 5;
    counter = 0;
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

void PlayGameComputer(){ //de Ai gaat spelen
    playerAlive = false; //zet de playerAlive op false voor de playagain functies
    sprays = 5;
    tryCounter = 1; //tellen hoe vaak de Ai de game heeft gespeeld met dezelfde configuratie
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
}*/