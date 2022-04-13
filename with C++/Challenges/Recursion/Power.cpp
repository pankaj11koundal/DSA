// Program to print the n upto power p;

#include<iostream>

using namespace std;

int power(int n, int p)
{
    if(p == 0)  
        return 1;

    return n * power(n, p - 1);
}

int main()
{
    int n, p;

    cout << "Enter the exponent: ";
    cin >> n;
    cout << "Enter the power: ";
    cin >> p;

    cout << power(n, p);

    return 0;
}