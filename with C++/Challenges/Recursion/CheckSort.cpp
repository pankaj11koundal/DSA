// Program to check whether a array is sorted or not

#include<iostream>

using namespace std;

bool checksort(int arr[], int n)
{
    if (n == 1)
    {
        return true;
    }
    
    return (arr[0] < arr[1] && checksort(arr + 1, n - 1 ));
}

int main()
{
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    int arr[n];
    cout << "Enter the elements in the array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> n;
    }
    
    if (checksort(arr, n))
    {
        cout << "The array is sorted ";
    }
    else
        cout << "The array is not sorted";
    
    return 0;
}