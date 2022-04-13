// Program to update the bit at given postion in the number either by 1 or 0.

#include<iostream>
#include<conio.h>

using namespace std;

int main()
{
    int num, pos, bit;
    cout << "Enter the number whose bit you want to update: ";
    cin >> num;

    cout << "Enter the position at which you want to update the bit: ";
    cin >> pos;

    cout << "Enter the bit which you want to update either 0 or 1: ";
    cin >> bit;

    num = (~(1 << pos)) & num;
    num = (bit << pos) | num;

    cout <<"Number after updating the bit at given position " << pos << " is " << num;

    return 0;
    getch();
}