	if(neighbourNeighbour(currentRoom, coronaRoom)){
            cout << "Something smells fishy " << endl;
			smellCorona = true;
        }
		else{
			smellCorona = false;

	// Als de hint dat de corona dichtbij is gegeven is, verhoog het aantal beurten dat de hint gegeven is met 1.
	if (smellCorona == true){
		turnsSmelled++;
	}
	else{
		turnsSmelled = 0;
	}
	
	// Als de corona vaker dan 1 keer geroken is en er nog sprays over zijn, spray in 1 van de buurkamers.
	if (turnsSmelled > 1 && sprays > 0){
		sprays--;
		vector<int> neighbours = read(currentRoom);
		int choice = rand() % 3;
		
		// Als het de kamer was met de corona, dan heeft de computer gewonnen.
		if(neighbours[choice] == coronaRoom){
			cout << "Splashhhhh!" << endl;
			cout << "The Corona is dead. You killed it!" << endl;
			cout << "Congratulations!! You win!!" << endl;
			coronaAlive = false; // Corona is dood
			PlayGame();
		}
		// Als het niet de goede kamer was beweegt de wumpus.
		else{
			cout << "Oh no!!, you missed the Corona!!" << endl;
			cout << "The Corona flew to another room " << endl;
			turnsSmelled = 0;
			moveCorona();
				// Als de corona naar de kamer dat de computer zat bewoog, dan heeft de computer verloren.
				if(coronaRoom == currentRoom){
					cout << "The Corona flew to your room" << endl;
					cout << "YOU ARE INFECTED, now you're dead. You suck, loser" << endl;
					PlayAgain();
				}
				else{
					// Als het spel nog niet voorbij is, ga naar de volgende beurt.
					InspectCurrentRoom();
				}
		}
	}
