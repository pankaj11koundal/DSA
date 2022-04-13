#include<iostream>

using namespace std;

bool isValid(int arr[], int mid, int n, int k)
{
    int sum;
    // cout << endl << sum;
    sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if (sum > mid)
        {
            sum = arr[i];
            k--;
        }
        
        if (k == 0)
        {
            return false;
        }
    }
    return true;
}

int assignMaxPages(int arr[], int start, int end, int n, int k)
{
    int res = -1, mid;

    if (k > n)
    {
        return res;
    }
    
    while (start <= end)
    {
        mid = (start + end) / 2; 
        if (isValid(arr, mid, n, k))
        {
            res = mid;
            end = mid - 1;
        }
        else{
            start = mid + 1;
        }
    }
    return res;
}

int main()
{
    int n, sum = 0, k;
    cout << "Enter the number of books: ";
    cin >> n;
    cout << "Enter the number of students: ";
    cin >> k;

    int pages[n];
    cout << "Enter the number of pages of each book: ";
    for (int i = 0; i < n; i++)
    {
        cin >> pages[i];
        sum += pages[i];
    }
    // cout<< sum << pages[n-1] << endl;
    cout << assignMaxPages(pages, pages[n - 1], sum, n, k);

    return 0;
}