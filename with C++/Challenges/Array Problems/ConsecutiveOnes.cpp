#include<bits/stdc++.h>

using namespace std;

int consecutiveOnes(int arr[], int n, int k)
{
    int zeroCounts = 0, start = 0 ,consecutiveOnes = 0;
    for (int i = 0; i < n; i++)
    {
        if(arr[i] == 0)
        {
            zeroCounts++;
        }

        while (zeroCounts > k)
        {
            if (arr[start] == 0)
            {
                zeroCounts--;
            }
            start++;
        }
        consecutiveOnes = max(consecutiveOnes, i - start + 1);
    }
    return consecutiveOnes;
}

int main()
{
    int n, k;
    cout << "Enter the size of the array: ";
    cin >> n;

    int arr[n];
    cout << "Enter the elements in the array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    
    cout << "Enter the number of flips: ";
    cin >> k;
    cout << consecutiveOnes(arr, n, k);

    return 0;
}