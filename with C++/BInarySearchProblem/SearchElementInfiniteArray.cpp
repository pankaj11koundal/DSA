#include <iostream>

using namespace std;

int binarySearch(int arr[], int start, int end, int key)
{
    int mid;
    while (start <= end)
    {
        mid = (start + end) / 2;
        if (arr[mid] == key)
        {
            return mid;
        }
        else if (key < arr[mid])
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

int searchElement(int arr[], int start, int end, int key)
{
    while (arr[end] < key)
    {
        if (arr[end] == key)
        {
            return end;
        }
        else if (arr[start] == key)
        {
            return start;
        }
        start = end;
        end = end * 2;
    }

    return binarySearch(arr, start, end, key);
}

int main()
{
    int n;
    cout << "Enter the size of array: ";
    cin >> n;

    int arr[n];
    cout << "Enetr the elements in array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int key;
    cout << "Enter the key: ";
    cin >> key;

    cout << searchElement(arr, 0, 1, key);

    return 0;
}