// This algorithm finds the maximum subarray's sum in O(n^2) time complexity. Another 
// algorithm which finds the maximum sum of subarray in just O(n) which is Kadane's algorithm


#include<iostream>
#include<climits>

using namespace std;

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

    int cursum[n + 1];
    cursum[0] = 0;

    for (int i = 1; i <= n; i++)
    {
        cursum[i] = cursum[i - 1] + arr[i - 1];
    }

    int maxsum = INT_MIN;

    for (int i = 1; i <= n; i++)
    {
        int sum = 0;
        for (int j = 1; j <= i; j++)
        {
            sum = cursum[i] - cursum[j -1];
            maxsum = max(maxsum, sum);
        }
    }
    
    cout << "The maximum sum of the subarray is " << maxsum;
}