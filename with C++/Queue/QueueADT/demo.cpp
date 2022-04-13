#include<iostream>
#include<conio.h>

using namespace::std;

int main()
{
    int size, *ptr;
    cout << "Enter the size of the array: ";
    cin >> size;
    ptr = new int[size];
    
    cout << "Enter the value in the array: \n";
    for (int i = 0; i <= size; i++)
    {
        cout << "Enter the element at position " << i << ": ";
        cin >> ptr[i];
    }

    cout << "Elements in the array: \n";
    for (int i = 0; i <= size; i++)
    {
        cout << "Element at position " << i << " is " << ptr[i] << "\n";
    }
    return 0;
}