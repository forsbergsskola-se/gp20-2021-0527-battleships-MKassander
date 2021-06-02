using namespace std;

#include <iostream>
#include <stdlib.h>
#include <time.h>

int main()
{
    cout << "Enter number of iterations:" << endl;
    float iterations;
    cin >> iterations;

    float pool[20] = {};
    int r;

    srand(time(0));

    for (int i = 0; i <= iterations; i++)
    {
        r = rand() % 20 + 1;
        pool[r - 1] += 1;
    }
    cout << endl;
    for (int i = 0; i < 20; i++)
    {
        float proc = (pool[i] / iterations) * 100;
        cout << i +1 << ": " << pool[i] << " (" << proc << " %)" << endl;
    }
}

/*
Test the rand() function!
Create a large number of random numbers between 1 and 20!

Count how often every number appears

Compare this to the ideal distribution (i.e. display propability of every number or something like that)
*/