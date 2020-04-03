void WumpusGame::InspectCurrentRoom() {
    srand (time(NULL));
    if(currentRoom == wumpusRoom){
        cout << "The Wumpus ate you!" << endl;
        cout << "You suck, loser" << endl;
        PlayAgain();
    }
    cout << "You are in room ";
    cout << currentRoom << endl;
    cout << "Tunnels lead to rooms " << endl;
    for (int j = 0; j < 3; j++)
    {
        cout << adjacentRooms[currentRoom][j];
        cout << " ";
    }
        cout << endl;
}
