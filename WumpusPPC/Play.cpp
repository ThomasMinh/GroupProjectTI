#include "WumpusFunctions.h"

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
    int newRoom;
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
	int o = rand() % 4 + 1;
	vector <int> naast = read(wumpusRoom);
	if(o == 1){
		wumpusRoom = wumpusRoom;
	}
	else if(o == 2) {
		wumpusRoom = naast[0];
	}
	else if(o == 3) {
		wumpusRoom = naast[1];
	}
	else if(o == 4) {
		wumpusRoom = naast[2];
	}
	write(map);
}

int Move(int newRoom){
    return newRoom;
}
