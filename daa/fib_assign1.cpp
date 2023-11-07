/*
Write a program non-recursive and recursive program to calculate Fibonacci numbers and
analyze their time and space complexity.
*/

#include <bits/stdc++.h>
using namespace std;

// non-recursive

int fib(int n)
{
    if (n <= 1)
    {
        return n;
    }

    int prev = 0;
    int current = 1;

    for (int i = 2; i <= n; i++)
    {
        int ans = prev + current;
        prev = current;
        current = ans;
    }

    return current;
}

// recursive
int fib_recursive(int n)
{
    if (n <= 1)
    {
        return n;
    }

    return fib_recursive(n - 1) + fib_recursive(n - 2);
}

int main()
{
    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    int result = fib(n);
    cout << "Fibonacci of " << n << " using non-recursive method : " << result << endl;

    int result2 = fib_recursive(n);
    cout << "Fibonacci of " << n << " using Recursive method : " << result2 << endl;

    return 0;
}

/*
1)NON-Recursive   Time complexity = O(n)    Space Complexity = O(1)
2)Recursive       Time complexity = O(2^n)    Space Complexity = O(n)
*/