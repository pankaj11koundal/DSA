#include<bits/stdc++.h>

using namespace std;

int trappingRainwaterHarvesting(int arr[], int n)
{   
    int maxHeight = INT_MIN;
    int left[n];
    int right[n];
    int blocks[n];
    int block = 0;

    for (int i = 0; i < n; i++)
    {
        maxHeight = max(maxHeight, arr[i]);
        left[i] = maxHeight;
    }

    maxHeight = INT_MIN;
    for (int i = n - 1; i >= 0; i--)
    {
        maxHeight = max(maxHeight, arr[i]);
        right[i] = maxHeight;
    }
    
    for (int i = 0; i < n; i++)
    {
        block += (min(left[i], right[i]) - arr[i]);
    }
    return block;
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
    
    cout << trappingRainwaterHarvesting(arr, n);

    return 0;
}