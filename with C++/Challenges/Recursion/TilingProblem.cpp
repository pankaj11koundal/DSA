// Program to find the number of ways to arrange the tiles of size 2*1 in 2*n floor

#include<iostream>

using namespace std;

int Tiling(int n)
{
    if (n == 0 || n == 1)
    {
        return n;
    }

    return Tiling(n - 1) + Tiling(n - 2);
}

int main()
{
    cout << Tiling(2);
}