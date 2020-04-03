void WumpusGame::PlayAgain(){
    char antwoord;
    cout << "Would you like to play again?Enter Y/N, enter Y to play again.";
    cin >> antwoord;
    if(antwoord == 'y' || antwoord == 'Y'){
        currentRoom = startingPosition;
        wumpusRoom = wumpusStart;
        cout << "Goodluck." << endl;
        InspectCurrentRoom();
    } else {
        playerAlive = false;
    }
    
}
