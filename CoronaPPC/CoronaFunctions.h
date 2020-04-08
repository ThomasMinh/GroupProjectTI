#ifndef CoronaFunctions_h
#define CoronaFunctions_h

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
void PlayGameComputer();
void moveComputer();
void PlayAgainComputer();
void write(vector<vector<int>> & numbers);
vector<int> read(int roomID);
void PlacePlayer();
void PlaceCorona();
void placePolice();
void placeQZones();
void placeVentilator();
bool IsRoomAdjacent(int roomA, int roomB);
bool isRoomValid(int newRoom);
bool neighbourNeighbour(int currentRoom, int coronaRoom); 
int Move(int newRoom);
void moveCorona();
void InspectCurrentRoom();
void PerformAction(int cmd);
void PlayAgain();



#endif /* CoronaFunctions_h */