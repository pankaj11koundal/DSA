#include<iostream>

using namespace std;

merging(int arr[], int mid, int l, int r)
{

    
}

void mergeSort(arr, l, r)
{
    if(l < r)
    {
        int mid = (l + r) / 2;

        mergeSort(arr, l, mid);
        mergeSort(arr, mid + 1, r);

        merging(arr, mid, l, r);
    }
}

int main()
{
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    int arr[n];
    cout << "Enter the elements: ";
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    mergeSort(arr, 0, n - 1);

    for(int i = 0; i < n; i++)
    {
        cout << arr[i];
    }
    return 0;
}