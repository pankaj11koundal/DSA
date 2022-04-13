// Program to show the steps for TOWER OF HANOI 

#include<iostream>

using namespace std;

void toh(int n, char source, char destination, char helper)
{
    if (n == 0)
    {
        return;
    }
    
    toh(n-1, source, helper, destination);
    cout << "Move " << source << " to " << destination << endl;
    toh(n-1, helper, destination, source);
}

int main()
{
    toh(4, 'A', 'B', 'C');

    return 0;
}
