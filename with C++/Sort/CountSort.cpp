#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void countSort(int arr[], int n)
{

    int count[10] = {0};
    int output[n];

    for (int i = 0; i < n; i++)
    {
        count[arr[i]]++;
    }

    for (int i = 1; i < 10; i++)
    {
        count[i] = count[i - 1] + count[i];
    }

    for (int i = n - 1; i >= 0; i--)
    {
        output[--count[arr[i]]] = arr[i];
    }

    for (int i = 0; i < n; i++)
    {
        arr[i] = output[i];
    }
}

int main()
{
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    countSort(arr, n);

    cout << "Array after sorting is " << endl;

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}