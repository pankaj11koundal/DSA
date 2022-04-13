#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n, minidx = INT_MAX;

    cout << "Enter the size of the array: ";
    cin >> n;

    int arr[n];

    // const int N = 1e6 + 2;
    int idx[1000];

    cout << "Enter the elements in the array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    for (int i = 0; i < 1000; i++)
    {
        idx[i] = -1;
    }
    

    for (int i = 0; i < n; i++)
    {
        if(idx[arr[i]] != -1)
        {
            if (minidx > idx[arr[i]])
            {
                minidx = idx[arr[i]];
                idx[arr[i]] = i;
            }        
        }
        else
            idx[arr[i]] = i;
    }

    if (minidx == INT_MAX)
    {
        cout << "The least repeating indes is " << -1;
    }
    else
        cout << "The least repeating index is " << minidx;
}