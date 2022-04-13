// Program to set the bit at specific position in the number

#include<iostream>

using namespace std;

int main()
{
    int num, pos;
    cout << "Enter the number whose bit you want to manipulate: ";
    cin >> num;

    cout << "Enter the position where you want to set the bit: ";
    cin >> pos;

    cout << "The value of the num after setting bit at " << pos << " is " << ((1 << pos) | num);

    return 0;
}
