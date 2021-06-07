using namespace std;

#include <iostream>
#include "Battleships.h"

int main()
{
	string P1Grid[100] = {};
	fill(begin(P1Grid), begin(P1Grid) + 100, "?");

	string P2Grid[100] = {};
	fill(begin(P2Grid), begin(P2Grid) + 100, "?");

	cout << "Player1 placement phase" << endl;
	ShipPlacement(P1Grid);

	ClearPage();

	cout << "Player2 placement phase" << endl;
	ShipPlacement(P2Grid);

	ClearPage();

	TakeTurns(P1Grid, P2Grid);
}

void TakeTurns(string grid1[], string grid2[]) {
	bool P1Turn = true;
	int P1Ships = 5, P2Ships = 5;


	while (true)
	{
		if (P1Turn) {
			cout << "Player1 turn" << endl;
			DisplayGrid(grid2, false);
		} 
		else {
			cout << "Player2 turn" << endl;
			DisplayGrid(grid1, false);
		}

		cout << "Enter coordinates to shoot" << endl;
		int gridCellNum = GetCoordinates();

		if (P1Turn) P2Ships -= Shoot(grid2, gridCellNum);
		else P1Ships -= Shoot(grid1, gridCellNum);

		cout << "P1 ships left: " << P1Ships << endl << "P2 ships left: " << P2Ships << endl << endl;

		if (P1Ships == 0)
		{
			cout << "P2 Wins!" << endl;
			break;
		}
		else if (P2Ships == 0)
		{
			cout << "P1 Wins!" << endl;
			break;
		}

		P1Turn = !P1Turn;
	}
}

int GetCoordinates() {
	cout << "a-j:" << endl;
	string letter;
	cin >> letter;

	cout << "0-9:" << endl;
	int number;
	cin >> number;
	return (number * 10) + CompareLetter(letter);
}

int Shoot(string grid[], int cellNum) {
	if (grid[cellNum] == "O")
	{
		cout << "HIT" << endl;
		grid[cellNum] = "X";
		DisplayGrid(grid, false);
		return 1;
	}
	else {
		cout << "MISS" << endl;
		if (grid[cellNum] == "X") cout << "You allready shot and hit this coordinate" << endl;
		grid[cellNum] = "M";
		DisplayGrid(grid, false);
		return 0;
	}
}

void ClearPage() {
	for (int i = 0; i < 30; i++)
	{
		cout << endl;
	}
}

void ShipPlacement(string grid[]) {
	int ships = 5;
	DisplayGrid(grid, true);

	while (ships > 0)
	{
		cout << "Ships left: " << ships << endl;

		while (true)
		{
			int gridCellNum = GetCoordinates();
			if (grid[gridCellNum] == "?")
			{
				grid[gridCellNum] = "O";
				break;
			}
		}
		cout << "Enter coordinates to place on" << endl;

		

		DisplayGrid(grid, true);

		--ships;
	}
}

int CompareLetter(string letter) {
	if (letter == "a") return 0;
	else if (letter == "b") return 1;
	else if (letter == "c") return 2;
	else if (letter == "d") return 3;
	else if (letter == "e") return 4;
	else if (letter == "f") return 5;
	else if (letter == "g") return 6;
	else if (letter == "h") return 7;
	else if (letter == "i") return 8;
	else if (letter == "j") return 9;
}

void DisplayGrid(string grid[], bool showShips) {
	cout << endl;
	int row = 0;
	int rowNumber = 0;
	cout << "  a b c d e f g h i j" << endl;
	cout << rowNumber << " ";
	for (int i = 0; i < 100; i++)
	{
		if (!showShips && grid[i] == "O") cout << "? ";
		else cout << grid[i] << " ";
		++row;
		if (row == 10)
		{
			cout << endl;
			row = 0;
			if (rowNumber < 9)
				cout << ++rowNumber << " ";
		}
	}
	cout << endl;
}

/*
The Rules:
2 Players

10 x 10 grid per player

Ships: sizes 5, 4, 3, 2 ships with 2

Ships may be placed vertically or horizontally

Ships may not overlap and may not touch each other (i.e. there needs to be at least 1 empty grid cell around the ship in every direction)

Players take alternating turns

Coordinates given in the form g7, a2, d2 etc...

Feedback "Hit" or "Miss"

Feedback "Ship sunk!"
*/