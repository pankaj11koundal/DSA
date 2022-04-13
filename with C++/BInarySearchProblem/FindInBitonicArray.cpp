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
}

int main()
{
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    int arr[n];
    cout << "Enter the elements in the array: ";
    for (int  i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    

    cout << arr[maxInBitonicArray(arr, 0, n - 1, n)];

    return 0;
}