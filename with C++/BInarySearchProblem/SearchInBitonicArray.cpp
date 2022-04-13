#include<iostream>

using namespace std;

int  maxInBitonicArray(int arr[], int start, int end, int n)
{
    int mid;
    while (start <= end)
    {
        mid = (start + end) / 2;

        if ((mid == 0 || arr[mid] > arr[mid + 1]) && (mid == n - 1 || arr[mid] > arr[mid - 1]))
        {
            return mid;
        }
        else if (mid > 0 && arr[mid] < arr[mid - 1])
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

    int pos = maxInBitonicArray(arr, 0, n - 1, n);
    if (arr[pos] == search)
    {
        cout << "Element found at pos ";
        return 0;
    }
    
    int left = reverseBinarySearch(arr, pos, n - 1, search);
    int right = binarySearch(arr, 0, pos, search);

    cout << max(left, right);
    return 0;
}