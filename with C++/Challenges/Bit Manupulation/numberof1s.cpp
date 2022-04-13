// To check number of 1s in a number

#include<iostream>

using namespace std;

int main()
{
    int num, count = 0;
    cout << "Enter the number: ";
    cin >> num;

    while(num)
    {
        num = num & (num - 1);
        count++;
    }

    cout << "The number of 1's in the binary represtation in the given number is " << count;
    return 0;
}
