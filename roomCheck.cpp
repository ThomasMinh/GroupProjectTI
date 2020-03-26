#include <vector>
#include <iostream>
using namespace std;

vector<int> validRooms (const int & room){
	vector<vector<int>> rooms =  {{2, 4, 8}, {1, 3, 7}, {2, 4, 6}, {1, 3, 5}, {4, 6, 8}, {3, 5, 7}, {2, 6, 8}, {1, 5, 7}};
	
	return rooms[room - 1];
}

bool isRoomValid(const int & currentRoom, const int & targetRoom){
	vector<int> rooms = validRooms(currentRoom);
	
	for(unsigned int i = 0; i < rooms.size(); i++){
		if (rooms[i] == targetRoom){
			return true;
		}
	}
	return false;
}
