#indef WUMPUSFUNCTIONS_H
#define WUMPUSFUNCTIONS_H

#include <vector>
#include <iostream>
#include <algorithm>
#include <random>
#include <chrono>
#include <cstring>
#include <fstream>
#include <sstream>
using namespace std;
        
int numRooms;
int currentRoom, startingPosition;
int wumpusRoom, wumpusStart, bat1Start, bat2Start;
bool playerAlive, wumpusAlive;
int batRoom, batRoom2, pitRoom, pitRoom2;
int bat, bat2, pit, pit2;
int arrows;
fstream WFile;
vector<vector<int>> map = generateMap();

vector<vector<int>> generateMap();
void PlayGame();
void write(vector<vector<int>> & numbers);
vector<int> read(int roomID);
void PlacePlayer();
void PlaceWumpus;
void placeBats();
void placePits();
bool IsRoomAdjacent(int roomA, int roomB);
int Move(int newRoom);
void InspectCurrentRoom();
void PerformAction(int cmd);
bool isRoomValid(int newRoom);
void PlayAgain();
bool neighbourNeighbour(int currentRoom, int wumpusRoom ); 
void moveWumpus();

#endif /* WUMPUSFUNCTIONS_H */