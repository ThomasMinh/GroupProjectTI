#include <vector>
using namespace std;

bool neighbourNeighbour(int currentRoom, int wumpusRoom){
	vector<int> neighbours = read(currentRoom);
	vector<int> neighboursOfNeighbour = {};
	
	for(unsigned int i = 0; i < neighbours.size(); i++){
		if (neighbours[i] == wumpusRoom){
			return true;
		}
		
		neighboursOfNeighbour = read(neighbours[i]);
		for(unsigned int j = 0; j < neighboursOfNeighbour.size(); j++){
			if (neighboursOfNeighbour[j] == wumpusRoom){
				return true;
			}
		}
	}
	return false;
}
