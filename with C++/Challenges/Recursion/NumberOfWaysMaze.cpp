// Program to find the number of ways to reach the desitation in the maze from its starting poistion using recursion

#include<iostream>

using namespace std;

int numberofwaysmaze(int n, int i, int j)
{
    if (i == n - 1 && j == n - 1)
    {
        return 1;
    }
    
    if (i >= n || j >= n)
    {
        return 0;
    }
    
    return numberofwaysmaze(n, i + 1, j) + numberofwaysmaze(n, i ,j + 1);
}

int main()
{
   cout << numberofwaysmaze(3, 0, 0);
}