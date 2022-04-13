#include <iostream>

using namespace std;

bool isSafe(int **arr, int x, int y, int n)
{
    for (int row = 0; row < x; row++)
    {
        if (x < n && y < n && arr[x][y] == 1)
            {
                return false;
            }
    }

    int row = x;
    int col = y;

    
}

int main()
{
    int n;
    cout << "Enter the size of the matrix: ";
    cin >> n;

    int **arr = new int *[10];

    for (int i = 0; i < n; i++)
    {
        arr[i] = new int[n];

        for (int j = 0; j < n; j++)
        {
            arr[i][j] = 0;
        }
    }

    return 0;
}