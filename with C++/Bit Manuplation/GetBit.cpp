// Program to get the specific bit either 0 or 1 at specific position from a number

#include<iostream>

using namespace std;

// function to return the bit of number num at postion pos
int getBit(int num, int pos)
{
    return ((1 << pos) & num);
}

int main()
{
    int x, i;
    cout << "Enter the number: ";
    cin >> x;

    cout << "Enter the bit position whose bit your want to get: ";
    cin >> i;

    if(getBit(x, i) != 0)
        cout << "The bit at " << i << "th position is " << 1;
    else  
        cout << "The bit at " << i << "th position is " << 0;
    
    return 0;
}