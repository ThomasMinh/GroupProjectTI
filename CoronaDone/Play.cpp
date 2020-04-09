/* void PlayAgain(){ //Als je dood gaat krijg je de optie om opnieuw te spelen
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
}*/