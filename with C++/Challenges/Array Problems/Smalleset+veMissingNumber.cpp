#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int  main()
{
    int n, N = 1000, ans = -1;
    bool Bool[N];

    cout << "Enter the size of the array: ";
    cin >> n;

    int arr[n];

    cout << "Enter the  element in the array: ";
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    for (int i = 0; i < N; i++)
    {
        Bool[i] = false;
    }
    
    for (int i = 0; i < n; i++)
    {
        if(arr[i] >= 0)
            Bool[arr[i]] = true;
    }

    for(int i = 0; i < N; i++)
    {
        if(Bool[i] == false)
        {
            ans = i;
            break;
        }
    }

    cout << ans;
}
