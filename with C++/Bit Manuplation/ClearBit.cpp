// Program to unset or clear the bit of given number num at given position pos

#include<iostream>

using namespace std;

int main()
{
    int num, pos;
    cout << "Enter the number whose bit you want to manipulate: ";
    cin >> num;

    cout << "Enter the postion at where you want to clear the bit: ";
    cin >> pos;

    num = (~(1 << pos) & num);
    cout << "Number after clearing the bit at position " << pos << " is " << num;

    return 0;
}
