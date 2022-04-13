#include<iostream>

using namespace std;

char nextAlphabet(char arr[], int start, int end, char key)
{
    int mid, res = -1;
    while (start <= end)
    {
        mid = (start + end) / 2;
        if (arr[mid] > key)
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
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    char arr[n];
    cout << "Enter the elements in the array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    
    char key;
    cout << "Enter the alphabet: ";
    cin >> key;

    cout << arr[nextAlphabet(arr, 0, n-1, key)];

    return 0;
}