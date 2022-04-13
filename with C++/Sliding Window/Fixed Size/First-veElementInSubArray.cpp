#include<iostream>
#include<queue>
#include<vector>

using namespace std;

int findNeg(int arr[], int n, int k, vector<int> &v)
{
    int i = 0, j = 0;
    queue<int> q;
    while (j < n)
    {
        if (arr[j] < 0)
        {
            q.push(arr[j]);
        }
        
        if (j - i + 1 < k)
        {
            j++;
        }
        else if (j - i + 1 == k)
        {
            if (q.empty())
            {
                v.push_back(0);
            }
            else
            {
                v.push_back(q.front());
            }

            if (q.front() == arr[i])
            {
                q.pop();
            }
            j++;
            i++;
        }
    }
}

int main()
{
    vector<int> v;
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    int arr[n];
    cout << "Enter the elements in the array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    
    findNeg(arr, n, 3, v);
    
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }

    return 0;
}