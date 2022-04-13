#include<iostream>
#include<climits>

using namespace std;

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
    
    cout << "Enter the sum of two elements: ";
    cin >> k;

    int N = 1.02e6;
    bool parr[N] = {false};

    for (int i = 0; i < n; i++)
    {
        if(arr[i] < k)
        {
            parr[arr[i]] = true;
        }
    }
    
    cout << "Till here done";

    int i = 0, j = 0, sum = 0;

    while (j < n && j + sum < k)
    {
        sum = j + i;
        j++;
    }
    cout << "Till here done";
    if (sum == k && parr[i] == true && parr[j - 1] == true)
    {
        cout << "The two numbers are: " << i << j - 1;
        exit(0);
    }
    else if (j == n)
    {
        j--;
    }
    cout << "Till here done";
    while (j < n)
    {
        sum += j;

        while(i < j && sum > k)
        {
            sum -= i;
            i--;
        }

        if (sum == k && parr[i] == true && parr[j - 1] == true)
        {
            cout << "The two elements are " << i + 1 << j;
            exit(0);
        }
    }
    return 0;
}
