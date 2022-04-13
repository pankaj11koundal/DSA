// This algorithm finds the maximum subarray's sum with time complexity of O(n) only.

#include<iostream>
#include<climits>

using namespace std;

int main()
{
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    int arr[n];
    cout << "Enter the element in the array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int currentsum = 0, maxsum = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        currentsum += arr[i];
        if (currentsum < 0)
        {
            currentsum = 0;
        }
        
        maxsum = max(maxsum, currentsum);
    }
    
    cout << "Maximum sum of the subarray is " << maxsum;
}