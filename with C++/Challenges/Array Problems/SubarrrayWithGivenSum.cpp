#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n, i = 0, j = 0, sum = 0, s;
    cout << "Enter the size of the array: ";
    cin >> n;

    int arr[n];

    cout << "Enter the sum of the subarray: ";
    cin >> s;

    cout << "Enter the elements in the array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    
    while (j < n && arr[j] + sum > s)
    {
        sum += arr[j];
        j++;
    }
    
    if(sum == s)
    {
        cout << "starting and ending index of subarray: " << 1 << " " << j;
    }

    while (j < n)
    {
        sum += arr[j];
        
        while(sum > s){
            sum -= arr[i];
            i++;
        }

        if(sum == s)
        {
            cout << "starting and ending index of subarray: " << i + 1 << " " << j + 1;
            break;
        }
        j++;
    }
}
