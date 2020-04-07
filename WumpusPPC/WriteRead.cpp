#include "WumpusFunctions.h"

void write(vector<vector<int>> & numbers){	// Write gegenereerde map en alle hazards naar een .txt bestand
	ofstream WFile("map.txt");

	for(unsigned int i=0; i<numbers.size();i++){	// Gaat elke waarde in de vector vector int langs
		for(unsigned int j=0; j<numbers[i].size();j++){
			WFile << numbers[i][j] << " ";	// Write alle buurkamers per regel bij elkaar naar map.txt
		}
        WFile << "\n";
	}
    WFile << "Wumpus is in room = " << wumpusRoom << "\n";	// Laat zien in welke kamers alle hazards zitten
    WFile << "batroom1 is room = " << batRoom << "\n";
    WFile << "batroom2 is room = " << batRoom2 << "\n";
    WFile << "pitroom1 is room = " << pitRoom << "\n";
    WFile << "pitroom2 is room = " << pitRoom2 << "\n";
 
	WFile.close();
}

vector<int> read(int roomID){	// Read de buurkamers van de gegeven kamer
    string Text = "";
    int number;
	int line = 0;
	int regel = roomID;
    vector<int> rooms;
	ifstream RFile("map.txt");

	while (line != regel && getline(RFile, Text)) {	// Telt door tot de regel van de gegeven kamer
		line++;
	}
	if(line == regel){	//  voegt dan de buurkamers toe aan rooms zodra de juiste regel is bereikt
        stringstream iss(Text);
        while(iss >> number){
            rooms.push_back(number);
        }
        RFile.close();
        }
    return rooms;
}
