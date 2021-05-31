#include <iostream>
using namespace std;

int fibonacciRecursive(int n) {
    if (n < 2) return n;
    return fibonacciRecursive(n - 1) + fibonacciRecursive(n - 2);
}

int fibonacciIteration(int n) {
    int a = 1, b = 1, c = 0;

    for (int i = 0; i < n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return c;
}

int main()
{
    while (true)
    {
        cout << "Enter a number:" << endl;
        int i;
        cin >> i;

        fibonacciRecursive(i);

        fibonacciIteration(i);
    }
}

/*
Fibonacci(n) is defined as:
Fibonacci(0) = 0
Fibonacci(1) = 1
Fibonacci(n) = Fibonacci(n-1) + Fibonacci(n-2)
Implement this function using recursion
Implement this function using iteration
Iteration defines an algorithm that is implemented using iterations (loops)
Rather than recursive (self-calling) function calls
Optional:

Try to compare the performance of each implementation
Can you notice a difference?
How do you explain that?
*/
