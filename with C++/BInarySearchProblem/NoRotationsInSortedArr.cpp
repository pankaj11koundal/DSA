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
    
    int mid = -1;
    findPivot(arr, 0, n - 1, n, mid);

    cout << mid << " " << arr[mid];

    return 0;
}