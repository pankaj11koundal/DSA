// Program to print the sum of first n numbers using recursion

#include<iostream>

using namespace std;

int sum(int n)
{
    if(n == 0)
    {
        return 0;
    }

    return n + sum(n - 1);
}

int main()
{
    int n;
    cout << "Enter the number upto where you want to find the sum: ";
    cin >> n;
    
    for (int i = 1; i <= n; i++)
    {
        cout << "The sum of first " << n << " natural number is " << sum(i) << endl;
    }
    
    return 0;
}