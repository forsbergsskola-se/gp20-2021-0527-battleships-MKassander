using namespace std;

#include <iostream>

int main()
{
	string grid[100] = {};
	fill(begin(grid), begin(grid) + 100, "x");

	while (true)
	{
		int row = 0;
		for (int i = 0; i < 100; i++)
		{
			cout << grid[i] << " ";
			++row;
			if (row == 10)
			{
				cout << endl;
				row = 0;
			}
		}

		cout << "Enter cell to place on:" << endl;
		int i;
		cin >> i;

		grid[i] = "O";

		cout << "Enter direction:" << endl;
		cin >> i;
	}
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