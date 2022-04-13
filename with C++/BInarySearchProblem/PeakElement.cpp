#include<iostream>

using namespace std;

int findPeakElement(int arr[], int start, int end, int n)
{
    int mid = (start + end) / 2;

    if ((mid == 0 || arr[mid] >= arr[mid - 1]) && (mid == n - 1 || arr[mid] > arr[mid + 1]))
    {
        return mid;
    }
    else if (mid > 0 && arr[mid] < arr[mid - 1] )
    {
        return findPeakElement(arr, start, mid - 1, n);
    }
    else
    {
        return findPeakElement(arr, mid + 1, end, n);
    }
}

int main()
{
    int n;
    cout << "Enter the size of array: ";
    cin >> n;

    int arr[n];
    cout << "Enter the elements in the array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    
    cout << findPeakElement(arr, 0, n - 1, n);

    return 0;
}
