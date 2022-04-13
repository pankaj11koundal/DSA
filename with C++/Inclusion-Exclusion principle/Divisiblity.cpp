#include<iostream>

using namespace std;

int divisible(int n, int a, int b)
{
    int c1, c2, c3;

    c1 = n / a;
    c2 = n / b;
    c3 = n / (a*b);

    return c1 + c2 - c3;
}

int main()
{
    int n, a, b;
    cout << "Enter the number upto divisible number you want to find: ";
    cin >> n;

    cout << "Enter the first number: ";
    cin >> a;
    
    cout << "Enter the second number: ";
    cin >> b;

    cout << "Numbers divisible by " << a << b << " is " << divisible(n, a, b);

    return 0;
}