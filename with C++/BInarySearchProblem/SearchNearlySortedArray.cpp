#include<iostream>

using namespace std;

int searchNearlySortedArray(int arr[], int start, int end, int key)
{
    int mid;
    while (start <= end)
    {
        mid = (start + end) / 2;
        if (arr[mid] == key)
        {
            return mid;
        }
        else if (arr[mid + 1] == key)
        {
            return mid + 1;
        }
        else if (arr[mid - 1] == key)
        {
            return mid - 1;
        }
        else if (arr[mid] > key)
        {
            end = mid - 2;
        }
        else 
        {
            start = mid + 1;
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
    
    int key;
    cout << "Enter the key: ";
    cin >> key;

    cout << searchNearlySortedArray(arr, 0, n - 1, key);

    return 0;
}