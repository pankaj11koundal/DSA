#include<iostream>

using namespace std;

int main()
{
    int n;
    cout << "Enter the number of rows and columns of the matrice respectively: ";
    cin >> n;

    int mat[n][n], temp;

    cout << "Enter the elements in the matrice: \n";
    for(int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> mat[i][j];
        }
        cout << "\n";
    }

    cout << "Elements in the matrice:\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << "\n";
    }
    
    // // code of transpose of matrice
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         mat1[i][j] = mat[j][i];
    //     }
    // }

    for (int i = 0; i <= n / 2; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (j >= i)
            {            
                temp = mat[i][j];
                mat[i][j] = mat[j][i];
                mat[j][i] = temp;
            }
        }
        
    }
    

    cout << "matrix after transpose: \n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}