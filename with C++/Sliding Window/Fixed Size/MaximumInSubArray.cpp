#include <iostream>
#include <bits/stdc++.h>

using namespace std;

vector<int> maximumInSubArray(int arr[], int size, int k)
{
    int i = 0, j = 0;
    queue<int> q;
    vector<int> v;
    while (j < size)
    {
        while (!q.empty() && q.front() < arr[j])
        {
            q.pop();
        }
        q.push(arr[j]);

        if (j - i + 1 < k)
        {
            j++;
        }
        else
        {
            v.push_back(q.front());

            if (q.front() == arr[i])
            {
                q.pop();
            }

            i++;
            j++;
        }
    }

    return v;
}

int main()
{
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    int arr[size];

    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    vector<int> v = maximumInSubArray(arr, size, 3);
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    
    return 0;
}