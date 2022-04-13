#include<iostream>

using namespace std;

int main()
{
    int r1, r2, c1, c2;

    cout << "Enter the row and column of first matrice: ";
    cin >> r1 >> c1;

    int mat1[r1][c1];
    
    cout << "Enter the row and column of second matrice: ";
    cin >> r2 >> c2;

    int mat2[r2][c2], mat3[r1][c2];    

    cout << "Enter the elements in the matrice 1: ";
    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c1; j++)
        {
            cin >> mat1[i][j];
        }
    }

    cout << "Enter the elements in the matrice 2: ";
    for (int i = 0; i < r2; i++)
    {
        for (int j = 0; j < c2; j++)
        {
            cin >> mat2[i][j];
        }
    }
    
    // Multiplication matrice code
    if (c1 == r2)
    {
        for (int i = 0; i < r1; i++)
        {
            for (int j = 0; j < r1; j++)
            {
                for (int k = 0; k < c2; k++)
                {
                    mat3[i][j] = (mat1[i][k] * mat2[k][j]) + (mat1[i][k] * mat2[k][j]);
                }   
            }
        }
    }
    else
    {
        cout << "Multiplication is not possible";
    }
    
    cout << "Element in the matrice 1: \n";
    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c1; j++)
        {
            cout << mat1[i][j] << " ";
        }
        cout << "\n";
    }
    

    cout << "Element in the matrice 2:\n ";
    for (int i = 0; i < r2; i++)
    {
        for (int j = 0; j < c2; j++)
        {
            cout << mat2[i][j] << " ";
        }
        cout << "\n";
    }

    cout << "Element in the matrice 3:\n ";
    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c2; j++)
        {
            cout << mat3[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;   
}
