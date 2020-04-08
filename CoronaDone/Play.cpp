/* void PlayAgain(){
    char antwoord;
    cout << "Would you like to play again with the same map? Enter Y/N. if you want to quit, press Q" << endl;
    cin >> antwoord;
    if(antwoord == 'y' || antwoord == 'Y'){
        currentRoom = startingPosition;
        coronaRoom = wumpusStart;
        policeRoom = police1Start;
        policeRoom2 = police2Start;
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
                            cout << "The Corona is dead. You killed it!" << endl;
                            cout << "Congratulations!! You win!!" << endl;
                            coronaAlive = false; //Wumpus is dood
                            PlayGame();
                        } 
                        else{
                            cout << "Oh no!!, you missed the Corona!!" << endl;
                            cout << "The Corona flew to another room " << endl;
                            moveCorona();
                            if(coronaRoom == currentRoom){
                                cout << "The Corona flew to your room" << endl;
                                cout << "YOU ARE INFECTED, now you're dead. You suck, loser" << endl;
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
}

void PlayGame(){
    srand (time(NULL));
    int choice;
    bool validChoice = false;
    vector<vector<int>> map = generateMap();
    
    srand(time(NULL));  // rand() zal hierdoor steeds een andere selectie van getallen genereren
    PlacePlayer();
    PlaceCorona();
    placePolice();
    placeQZones();
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
}*/