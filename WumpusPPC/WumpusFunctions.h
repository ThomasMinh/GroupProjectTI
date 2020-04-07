#ifndef WumpusFunctions_h
#define WumpusFunctions_h

#include <vector>
#include <iostream>
#include <algorithm>
#include <random>
#include <chrono>
#include <cstring>
#include <fstream>
#include <sstream>
using namespace std;

void StartGame();
void instructions();
vector<vector<int>> generateMap();
void PlayGame();
void write(vector<vector<int>> & numbers);
vector<int> read(int roomID);
void PlacePlayer();
void PlaceWumpus();
void placeBats();
void placePits();
bool IsRoomAdjacent(int roomA, int roomB);
bool isRoomValid(int newRoom);
bool neighbourNeighbour(int currentRoom, int wumpusRoom); 
int Move(int newRoom);
void moveWumpus();
void InspectCurrentRoom();
void PerformAction(int cmd);
void PlayAgain();



#endif /* WumpusFunctions.h */