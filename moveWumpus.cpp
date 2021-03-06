void WumpusGame::PerformAction(int cmd) {
    int newRoom;
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
                            cout << "To return to the main menu please press 'Y'" << endl;
                            wumpusAlive = false; //Wumpus is dood
                            cin >> newRoom;
                            cin.clear();
                            cin.ignore(10000, '\n');
                        }
                        else{
                            cout << "Oh no!!, you missed the Wumpus!!" << endl;
							void WumpusGame::moveWumpus()
                            void WumpusGame::PlayGame(){
  int choice;
  bool validChoice = false;
 
    PlacePlayer();
    PlaceWumpus();
    placeBats();
    placePits();
    
    //vector<vector<int>> locations;
    //locations.push_back()
    
 
    playerAlive = true;
    wumpusAlive = true;
    arrows = 5;
    
    InspectCurrentRoom();
 
    while (playerAlive)
    {
        cout << "Enter an action choice." << endl;
        cout << "1) Move" << endl;
        cout << "2) Quit" << endl;
        cout << ">>> ";
 
        do
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
 
void WumpusGame::PlayGame(){
  int choice;
  bool validChoice = false;
 
    PlacePlayer();
    PlaceWumpus();
    placeBats();
    placePits();
    
    //vector<vector<int>> locations;
    //locations.push_back()
    
 
    playerAlive = true;
    wumpusAlive = true;
    arrows = 5;
    
    InspectCurrentRoom();
 
    while (playerAlive)
    {
        cout << "Enter an action choice." << endl;
        cout << "1) Move" << endl;
        cout << "2) Quit" << endl;
        cout << ">>> ";
 
        do
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
}

void WumpusGame::moveWumpus(){
	int o = rand() % 4 + 1;
	vector <int> naast = read(wumpusRoom);
	if(o = 1){
		wumpusRoom = wumpusRoom;
	}
	else if(o = 2) {
		wumpusRoom = naast[0];
	}
	else if(o = 3) {
		wumpusRoom = naast[1];
	}
	else if(o = 4) {
		wumpusRoom = naast[2];
	}
	
 }
