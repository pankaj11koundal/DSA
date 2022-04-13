#include<iostream>

using namespace std;

int firstOccurence(int arr[], int start, int end, int key)
{
    int mid, res;

    while (start <= end)
    {
        mid = (start + end) / 2;

        if (arr[mid] == key)
        {
            res = mid;
            end = mid - 1;
        }
        else if ( arr[mid] > key)
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return res;
}

int findFirst1InInFinite(int arr[], int start, int end)
{
    while (start < end)
    {
        if (arr[start] == 1)
        {
            return start;
        }
        else if (arr[end] == 1)
        {
            break;
        }
        else
        {
            start = end;
            end = end * 2;
        }
    }
    
    return firstOccurence(arr, start, end, 1);
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
    
    cout << findFirst1InInFinite(arr, 0, 1);

    return 0;
}