#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int calcMaxSum(int arr[], int n, int k)
{
    int i = 0, j = 0, sum = 0, maxSum = INT_MIN;

    while (j < n)
    {
        if (j - i + 1 < k)
        {
            sum += arr[j];
            j++;
        }
        if (j - i + 1 == k)
        {
            sum += arr[j];
            maxSum = max(maxSum, sum);
            sum -= arr[i];
            i++;
            j++;
        }
    }
    return maxSum;
}

int main()
{
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    int arr[n];
    cout << "Enter the elements in the array:";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
     

    cout << calcMaxSum(arr, n, 3);
    return 0;
}