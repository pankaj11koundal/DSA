// program to find the greatest common factor

#include <iostream>

using namespace std;

int GCD(int a, int b)
{
    int n;

    while (b != 0)
    {
        n = a % b;
        a = b;
        b = n;
    }

    return a;
}

int main()
{
    int a, b;
    cout << "Enter the first number: ";
    cin >> a;

    cout << "Enter the second number: ";
    cin >> b;

    cout << "Greatest common division of " << a << " and " << b << " is " << GCD(a, b);
}