#include<iostream>

using namespace std;

int lastOccurence(int arr[], int start, int end, int key)
{
    int mid, res;

    while (start <= end)
    {
        mid = (start + end) / 2;
        if (arr[mid] == key)
        {
            res = mid;
            start = mid + 1;
        }
        else if (arr[mid] < key)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return res;
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

    cout << lastOccurence(arr, 0, n - 1, key);

    return 0;
}