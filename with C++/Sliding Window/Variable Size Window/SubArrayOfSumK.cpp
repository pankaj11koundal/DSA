#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int findKSum(int arr[], int n, int k)
{
    int j = 0, i = 0, sum = 0, maxLen = INT_MIN;

    while (j < n)
    {
        sum += arr[j];

        if (sum >= k)
        {
            while (sum > k)
            {
                sum -= arr[i];
                i++;
            }
            
            if (sum == k)
            {
                maxLen = max(maxLen, j - i + 1);
            }
        }
        j++;
    }
    return maxLen;
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
    
    int k;
    cout << "Enter the sum: ";
    cin >> k;

    cout << findKSum(arr, n, k);

    return 0;
}