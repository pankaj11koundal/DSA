#include<iostream>
#include<conio.h>

using namespace std;

void swap (int arr[], int i, int n)
{
    int temp = arr[i];
    arr[i] = arr[n -1];
    arr[n -1] = temp;
}

void UpHeap(int i, int arr[])
{
    int temp, p = i / 2;
    if (arr[i] > arr[p])
    {   
        // swap(arr, i, p);
        temp = arr[i];
        arr[i] = arr[p];
        arr[p] = temp;
        UpHeap(p, arr);
    }
}


void HeapSort(int arr[], int n, int i)
{
    // cout << "\n Inside the heap sort function";
    int l = i * 2 + 1, r = i * 2 + 2, largest;
    if (arr[l] > arr[r])
    {
        largest = l;
    }
    else
    {
        largest = r;
    }
    
    swap(arr, largest, i);
    int temp = arr[largest];
    arr[largest] = arr[i];
    arr[i] = temp;
    HeapSort(arr, n -1 ,largest);
    return;
}

void Delete(int arr[], int n, int i)
{
    cout << "Inside Delete function.";
    // swap(arr, i, n);
    int temp = arr[i];
    arr[i] = arr[n-1];
    arr[n-1] = temp;
    HeapSort(arr, n-1, i);
}


int main()
{
    int arr[50], n, i;
    clearerr;

    cout << "Enter the size of the array: ";
    cin >> n;

    cout << "Enter the elements in the array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    UpHeap(i, arr);

    cout << "Elements in the array before sorting: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    
    // Delete(arr, n, 0);

    cout << "\nElements in the array after sorting: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}
