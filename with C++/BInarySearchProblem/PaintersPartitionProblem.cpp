#include<iostream>

using namespace std;

int isValid(int arr[], int mid, int n, int m)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if (sum > mid)
        {
            sum = arr[i];
            --m;    
        }
        
        if (m == 0)
        {
            return false;
        }        
    }
    return true;
}

int assignBoards(int arr[], int start, int end, int n, int m)
{
    int mid, res = -1;
    if (m > n)
    {
        return res;
    }

    while (start <= end)
    {
        mid = (start + end) / 2;
        if (isValid(arr, mid, n, m))
        {
            res = mid;
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return res;
}

int main()
{
    int n, sum = 0;
    cout << "Enter the number of boards: ";
    cin >> n;

    int m;
    cout << "Enter the number of painters: ";
    cin >> m;

    int boards[n];
    cout << "Enter the length of each board: ";
    for (int i = 0; i < n; i++)
    {
        cin >> boards[i];
        sum += boards[i];
    }
    
    cout << assignBoards(boards, boards[n - 1], sum, n, m);

    return 0;
}