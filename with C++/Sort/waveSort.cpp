// Program to implement the wave sort algorithm

#include<iostream>

using namespace std;

void waveSort(int arr[], int n)
{
    int temp;
    for (int i = 1; i < n; i = i + 2)
    {
        if (arr[i] > arr[i - 1])
        {
            temp = arr[i];
            arr[i] = arr[i - 1];
            arr[i - 1] = temp;
        }

        if (arr[i] > arr[i + 1] && i < (n - 2))
        {
            temp = arr[i];
            arr[i] = arr[i + 1];
            arr[i + 1] = temp;
        }
    }
}

int main()
{
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    int arr[n];
    cout << "Enter the elements in the array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    waveSort(arr, n);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    
    
}