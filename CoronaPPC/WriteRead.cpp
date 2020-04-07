/*void write(vector<vector<int>> & numbers){
	ofstream WFile("map.txt");

	for(unsigned int i=0; i<numbers.size();i++){
		for(unsigned int j=0; j<numbers[i].size();j++){
			WFile << numbers[i][j] << " ";
		}
        WFile << "\n";
	}
    WFile << "Wumpus is in room = " << wumpusRoom << "\n";
    WFile << "batroom1 is room = " << batRoom << "\n";
    WFile << "batroom2 is room = " << batRoom2 << "\n";
    WFile << "pitroom1 is room = " << pitRoom << "\n";
    WFile << "pitroom2 is room = " << pitRoom2 << "\n";
 
	WFile.close();
}

vector<int> read(int roomID){
    string Text = "";
    int number;
	int line = 0;
	int regel = roomID;
    vector<int> rooms;
	ifstream RFile("map.txt");

	while (line != regel && getline(RFile, Text)) {
		line++;
	}
	if(line == regel){
        stringstream iss(Text);
        while(iss >> number){
            rooms.push_back(number);
        }
        RFile.close();
        }
    return rooms;
}*/