void WumpusGame::PlaceWumpus(){
    bool validRoom = false;
    while(!validRoom){
        int randomRoom = rand() % 20;
        if(randomRoom != startingPosition){
            validRoom = true;
            wumpusRoom = randomRoom;
            wumpusStart = wumpusRoom;
        }
    }
}
