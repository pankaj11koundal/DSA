// C++ program to implement the selection sort

#include<iostream>
#include<conio.h>

using namespace :: std;

int main()
{
    int arr[100], n, smallest, temp, a;

    cout << "Enter the size of the array: ";
    cin >> n;

    cout << "Enter the elements in the array:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    
    cout << "Elements in the array before sorting:\n";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    
    for (int i = 0; i < n - 1; i++)
    {
        a = i;
        smallest = arr[i];
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < smallest)
            {
                a = j;
                smallest = arr[j];
            }
        }
        
        temp = arr[i];
        arr[i] = arr[a];
        arr[a] = temp;
        
    }

    cout << "\nElements in the array after sorting:\n";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    

}