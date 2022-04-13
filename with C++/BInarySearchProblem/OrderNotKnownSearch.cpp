#include<iostream>

using namespace std;

int binarySearch(int arr[], int start, int end, int search)
{
    int mid;
    while (start <= end)
    {
        mid = (start + end) / 2;

        if (arr[mid] == search)
        {
            return mid;
        }
        else if (arr[mid] > search)
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return -1;
}

int reverseBinarySearch(int arr[], int start, int end, int search)
{
    int mid;
    while (start <= end)
    {
        mid = (start + end) / 2;

        if (arr[mid] == search)
        {
            return mid;
        }
        else if (arr[mid] > search)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return -1;
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
    
    int search;
    cout << "Enter the element you want to search: ";
    cin >> search;

    if (n - 1 == 0 && arr[0] == search)
    {
        cout << "Element found at 0";
    }
    
    if (arr[0] > arr[1])
    {
        cout << "Array is in descending order " << endl;
        cout << "Element found at " << reverseBinarySearch(arr, 0, n - 1, search);
    }
    else
    {
        cout << "Array is in ascending order " << endl;
        cout << "Element found at " << binarySearch(arr, 0 , n - 1, search);
    }
    
    return 0;
}