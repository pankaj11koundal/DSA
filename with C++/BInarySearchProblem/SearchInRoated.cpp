#include<iostream>

using namespace std;

void findPivot(int arr[], int start, int end, int N, int &mid)
{
    if (start > end)
    {
        return;
    }
    
    mid = (start + end) / 2;

    if (arr[mid] < arr[mid - 1] && arr[mid] < arr[mid + 1])
    {
        findPivot(arr, start, (mid + N - 1) % N, N, mid);
        return;
    }
    else if (arr[mid] < arr[end])
    {
        findPivot(arr, start, (mid + N - 1) % N, N, mid);
        return;
    }
    else if (arr[mid] > arr[start])
    {
        findPivot(arr, (mid + 1) % N, end, N, mid);
        return;
    }
}

int findElement(int arr[], int start, int end, int search)
{
    if (start > end)
    {
        return -1;
    }
    
    int mid = (start + end) / 2;

    if (arr[mid] == search)
    {
        return mid;
    }
    else if (search < arr[mid])
    {
        findElement(arr, start, mid - 1, search);
    }
    else
    {
        findElement(arr, mid + 1, end, search);
    }
}


int main()
{
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    int arr[n];
    cout << "Enter the elements in the array: ";        // 11 12 13 14 1 2 3 4
    for (int i = 0; i < n; i++)                         // 0  1  2  3  4 5 6 7
    {
        cin >> arr[i];
    }

    int search;
    cout << "Enter the element you want to search: ";
    cin >> search;
    
    int mid = -1;
    findPivot(arr, 0, n - 1, n, mid);

    if (arr[mid] == search)
    {
        cout << "Element found at " << mid;
        exit(0);
    }
    
    
    int left = findElement(arr, 0, mid - 1, search);
    int right = findElement(arr, mid + 1, n - 1, search);

    cout << max(left, right);
    return 0;
}
