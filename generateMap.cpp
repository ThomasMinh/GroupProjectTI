#include <vector>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <random>
#include <chrono>
using namespace std;

vector<vector<int>> generateMap(){
	srand (time(NULL));
	vector<vector<int>> map = {};
	vector<vector<int>> sortedMap = {};
	vector<int> room = {};
	vector<int> roomNumbers = {};
	
	for(int i = 1; i <= 20; i++){
		roomNumbers.push_back(i);
	}
	
	auto rng = default_random_engine(chrono::system_clock::now().time_since_epoch().count());
	shuffle (roomNumbers.begin(), roomNumbers.end(), rng);
	
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
	
	for(int i = 1; i <= 20; i++){
		for(int j = 0; j < 20; j++){
			if (roomNumbers[j] == i){
				sortedMap.push_back(map[j]);
				break;
			}
		}
	}
	
	return sortedMap;
}

