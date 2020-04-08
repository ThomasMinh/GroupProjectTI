#include "CoronaFunctions.h"

vector<vector<int>> generateMap(){
	vector<vector<int>> map = {}; 
	vector<vector<int>> sortedMap = {};
	vector<int> room = {};
	vector<int> roomNumbers = {};
	
	// Voeg de rooms 1 t/m 20 toe aan een vector.
	for(int i = 1; i <= 20; i++){
		roomNumbers.push_back(i);
	}
	
	// Shuffle de vector zodat ze een een random plaats in de vector krijgen.
	auto rng = default_random_engine(chrono::system_clock::now().time_since_epoch().count());
	shuffle (roomNumbers.begin(), roomNumbers.end(), rng);
	
	// Maak connecties tussen de rooms en voeg die toe aan de map
	for(int i = 0; i < 20; i++){
		room = {};
		
		if (i == 0){
			room.push_back(roomNumbers[20-1]);
		}
		else{
			room.push_back(roomNumbers[i-1]);
		}


		if (i < 10){
			room.push_back(roomNumbers[i+10]);
		}
		else{
			room.push_back(roomNumbers[i-10]);
		}
		
		
		if (i == 20 - 1){
			room.push_back(roomNumbers[0]);
		}
		else{
			room.push_back(roomNumbers[i+1]);
		}
		map.push_back(room);
	}
	
	// Sorteer de map zodat de buurkamers van de juiste kamer op de juiste index in de vector staan.
	// (1e index is 1e kamer, 2e index 2e kamer, etc.
	for(int i = 1; i <= 20; i++){
		for(int j = 0; j < 20; j++){
			if (roomNumbers[j] == i){
				sortedMap.push_back(map[j]);
				break;
			}
		}
	}
	// return de gesorteerde map.
	return sortedMap;
}
