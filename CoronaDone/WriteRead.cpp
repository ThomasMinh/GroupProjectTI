/*void write(vector<vector<int>> & numbers){ //schrijft de map en hazards naar map.txt
	ofstream WFile("map.txt");

	for(unsigned int i=0; i<numbers.size();i++){ // Gaat elke waarde in de vector vector int langs
		for(unsigned int j=0; j<numbers[i].size();j++){
			WFile << numbers[i][j] << " "; // Write alle buurkamers per regel bij elkaar naar map.txt
		}
        WFile << "\n";
	}
    WFile << "corona is in room = " << coronaRoom << "\n"; // Laat zien in welke kamers alle hazards zitten
    WFile << "PoliceRoom1 is room = " << policeRoom << "\n";
    WFile << "PoliceRoom2 is room = " << policeRoom2 << "\n";
    WFile << "QuarantineZone1 is room = " << qZoneRoom << "\n";
    WFile << "QuarantineZone2 is room = " << qZoneRoom2 << "\n";
    WFile << "The fan is in room = " << ventRoom << "\n";
 
	WFile.close();
}

vector<int> read(int roomID){ // Read de buurkamers van de gegeven kamer vanuit de map.txt
    string Text = "";
    int number;
	int line = 0;
	int regel = roomID;
    vector<int> rooms;
	ifstream RFile("map.txt");

	while (line != regel && getline(RFile, Text)) { // Haalt de lines uit de map.txt bestand en Telt door tot de regel van de gegeven kamer
		line++;
	}
	if(line == regel){ // voegt dan de buurkamers toe aan rooms zodra de juiste regel is bereikt
        stringstream iss(Text); //Om een string om te kunnen zetten naar een vector int
        while(iss >> number){
            rooms.push_back(number);
        }
        RFile.close();
        }
    return rooms; //return de vector int van buurkamers
}*/