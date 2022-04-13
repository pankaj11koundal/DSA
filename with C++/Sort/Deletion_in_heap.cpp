// C++ program to implement the deletion in Heap 

#include<iostream>
#include<conio.h>

using namespace std;

int n;

void DownHeap(int arr[], int i, int &n)
{
    int l = i * 2 + 1, r = i * 2 + 2 ,temp ,largest;
    arr[i] = arr[n];


    if (l < n && arr[l] > arr[r])
    {
        largest = l;
    }
    else if (r < n && arr[r] > arr[l])
    {
        largest = r;
    }
    else
    {
        largest = i;
    }

    if (largest != i)
    {
        temp = arr[i]; 
        arr[i] = arr[largest];
        temp = arr[i];

        DownHeap(arr, largest, n);
    }
    else
    {
        return;
    }
}

int DeleteMaxHeap(int arr[], int i, int &n)
{
 
   int item = arr[i];
   arr[i] = arr[n -1];
   n--;
   DownHeap(arr, i, n);
   return item;
}

int main()
{
    int arr[50], n;

    cout << "Enter the size of the heap: ";
    cin >> n;
    
    cout << "Enter the elements in the heap: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "Deleted Item is: " << DeleteMaxHeap(arr, 0, n) << "\n";

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " " ;
    }
    
    cout << "Size of array afte deletion is " << n;

    return 0;
}