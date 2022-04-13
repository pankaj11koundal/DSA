#include<iostream>

using namespace std;

int findFloor(int arr[], int start, int end, int key)
{
    int mid, res;

    while (start <= end)
    {
        mid = (start + end) / 2;
        if (arr[mid] == key)
        {
            return mid;
        }
        else if (arr[mid] < key)
        {
            res = mid;
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }

    return res;
}

int findCiel(int arr[], int start, int end, int key)
{
    int mid, res;
    while (start <= end)
    {
        mid = (start + end) / 2;
        if (arr[mid] == key)
        {
            return mid;
        }
        else if (arr[mid] > key)
        {
            res = mid;
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return res;
}

int findMinimumDifferenceSorted(int arr[], int start, int end, int key)
{
    int left = findFloor(arr, start, end, key);
    int right = findCiel(arr, start, end, key);

    int mid = (start + end) / 2;

    return min(arr[mid], min(left, right));
}

int main()
{
    int n; 
    cout << "Enter the size of elements: ";
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

    cout << arr[findMinimumDifferenceSorted(arr, 0, n - 1, key)];

    return 0;
}