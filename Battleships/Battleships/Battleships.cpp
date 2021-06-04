using namespace std;

#include <iostream>

void ShipPlacement(string grid[]);
void ClearPage();
void DisplayGrid(string grid[]);
int CompareLetter(string letter);

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


}

void TakeTurns(string grid1[], string grid2[]) {
	bool P1Turn = true;

	while (true)
	{
		if (P1Turn) cout << "Player1 turn" << endl;
		else cout << "Player2 turn" << endl;

		cout << "Enter coordinates to shoot" << endl << "a-j:" << endl;
		string letter;
		cin >> letter;

		cout << "0-9:" << endl;
		int number;
		cin >> number;

		int gridCellNum = (number * 10) + CompareLetter(letter);

		if (P1Turn) Shoot(grid2, gridCellNum);
		else Shoot(grid1, gridCellNum);
		//kolla skepp kvar & om ^ funkar
	}
}

void Shoot(string grid[], int cellNum) {
	if (grid[cellNum] == "o")
	{
		cout << "HIT" << endl;
		grid[cellNum] = "x";
	}
	else cout << "MISS" << endl;
}

void ClearPage() {
	for (int i = 0; i < 30; i++)
	{
		cout << endl;
	}
}

void ShipPlacement(string grid[]) {
	int ships = 5;
	while (ships > 0)
	{
		cout << "Ships left: " << ships << endl;

		DisplayGrid(grid);

		cout << "Enter coordinates to place on" << endl << "a-j:" << endl;
		string letter;
		cin >> letter;

		cout << "0-9:" << endl;
		int number;
		cin >> number;

		int gridCellNum = (number * 10) + CompareLetter(letter);
		grid[gridCellNum] = "O";

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

void DisplayGrid(string grid[]) {
	cout << endl;
	int row = 0;
	int rowNumber = 0;
	cout << "  a b c d e f g h i j" << endl;
	cout << rowNumber << " ";
	for (int i = 0; i < 100; i++)
	{
		cout << grid[i] << " ";
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