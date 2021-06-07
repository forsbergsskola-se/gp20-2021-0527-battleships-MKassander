using namespace std;

#include <iostream>

#pragma once

void ShipPlacement(string grid[]);
void ClearPage();
void DisplayGrid(string grid[], bool showShips);
int CompareLetter(string letter);
int Shoot(string grid[], int cellNum);
void TakeTurns(string grid1[], string grid2[]);
int GetCoordinates();