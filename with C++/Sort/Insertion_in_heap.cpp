// c++ program to implement the insertion in heap(Max Heap)

#include<iostream>
#include<conio.h>

using namespace std;

int n;

void MaxHeap(int arr[], int i)
{
    int p, temp;
    if (i % 2 == 0)
    {
      p = (i / 2) - 1;
    }
    else
    {
        p = i / 2;
    }

    if (arr[i] > arr[p])
    {
        temp = arr[i];
        arr[i] = arr[p];
        arr[p] = temp;

        MaxHeap(arr, p);
    }
    else
    {
        return;
    }
}

int main()
{
    int arr[50], i;

    cout << "Enter the size of the heap array: ";
    cin >> n;

    cout << "Enter the elements in the heap array: ";
    for ( i = 0; i < n; i++)
    {
        cin >> arr[i];
        MaxHeap(arr, i);
    }
    
    cout << "Elements in the heap array: ";
    for ( i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    
    return 0;
}
