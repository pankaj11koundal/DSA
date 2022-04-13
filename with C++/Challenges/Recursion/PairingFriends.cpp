// We have n number of friends and they can be either single or in pair 

#include<iostream>

using namespace std;

int pairingfriends(int n)
{
    if (n == 0 || n == 1 || n == 2)
    {
        return n;
    }
    
    return pairingfriends(n - 1) + pairingfriends(n - 2)*(n-1);
}

int main()
{

    cout << pairingfriends(3);
    return 0;
}