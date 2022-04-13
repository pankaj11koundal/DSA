// It is an borad problem using recursion, in which we have to count the number of ways to reach the end position from the start our moves will be decided with the rolling of dice 

#include<iostream>

using namespace std;

int numberofways(int s, int e)
{
    if (s == e)
    {
        return 1;
    }
    if(s > e)
    {
        return 0;
    }

    int count = 0;
    for (int i = 1; i <= 6; i++)
    {
        count += numberofways(i + s, e);
    }
    
    return count;
}

int main()
{
    cout << numberofways(0,4);
}