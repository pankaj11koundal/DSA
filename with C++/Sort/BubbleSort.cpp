// C++ program to implement the Bubble Sort 

#include<iostream>
#include<conio.h>

using namespace :: std;

int main()
{
    int ar[100], n, temp;

    cout << "Enter the size of the array: ";
    cin >> n;

    cout << "Enter the elements in the array: ";
    for(int i = 0; i < n; i++)
    {
        cin >> ar[i];
    }

    cout << "Elements in the array before sorting:\n";
    for (int i = 0; i < n; i++)
    {
        cout << ar[i] << " ";
    }

    for(int i = 1; i < n - 1; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            if(ar[j] > ar[j + 1])
            {
                temp = ar[j];
                ar[j] = ar[j + 1];
                ar[j + 1] = temp;
            }
        }
        
    }

    cout << "Elements in the array after sorting: \n";
    for (int i = 0; i < n; i++)
    {
        cout << ar[i] << " ";
    }
        
    return 0;
}