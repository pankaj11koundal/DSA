// Searching an element in the matrice where both the element oriented in row and column are sorted

#include<iostream>

using namespace std;

int main()
{
    int r, c;
    cout << "Enter the row and column of the matrice: ";
    cin >> r >> c;

    int m[r][c];
    cout << "Enter the element in the matrice: ";
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> m[i][j];
        }
    }
    
    int search, i = 0, j = c - 1;
    bool found = false;
    cout << "Enter the element you want to search in the matrice: ";
    cin >> search;

    while(i < r && j >= 0)
    {

        if (search == m[i][j])
        {
            found = true;
            break;
        }
        else if (m[i][j] < search)
        {
    
            i++;
        }
        else
        {
            --j;
        }
    }

    if (found)
    {
        cout << "Element found at " << i + 1 <<" row " << j + 1 <<" column";
    }
    else
    {
        cout << "Element not found";
    }
}