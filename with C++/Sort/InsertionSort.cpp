// C++ program to execute the insertion sort

#include<iostream>
#include<conio.h>

using namespace::std;

int main()
{
    int arr[100], n, temp, k, ptr;

    cout << "Enter the size of the array(one space is reserved for least element): ";
    cin >> n;

    cout << "Enter the elements in the array(should be more than -10): ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "Elements in the array before sorting: ";
    for (int i = 1; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    for (int i = 1; i < n; i++)
    {
        temp = arr[i];
        ptr = i - 1;

        while (temp < arr[ptr])
        {
            arr[ptr + 1] = arr[ptr];
            ptr = ptr - 1;
        }

        arr[ptr + 1] = temp;
    }
    
    cout << "\nElements in the array after sorting: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}