// Program to find the first and last occurence of an number

#include<iostream>

using namespace std;

// First occurence of number
int firstocc(int arr[], int n, int key, int i)
{
    if(arr[i] == key)
    {
        return i;
    }
    if (i == n)
    {
        return -1;
    }
    
    firstocc(arr, n, key, i + 1);
}

// last occurence of number
int lastocc(int arr[], int n, int key, int i)
{
    if (i == n)
    {
        return -1;
    }
    
    int prevarr = lastocc(arr, n, key, i + 1);

    if(prevarr != -1)
    {
        return prevarr;
    }

    if (arr[i] == key)
    {
        return i;
    }

    return -1;
}

int main()
{
    int n, key;
    cout << "Enter the size of the array: ";
    cin >> n;

    cout << "Enter the key: ";
    cin >> key;

    int arr[n];

    cout << "Enter the elements in the array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    
    cout << "First occurence of " << key << " is " << firstocc(arr, n, key, 0);
    cout << "Last occurence of " << key << " is " << lastocc(arr, n, key, 0);

    return 0;
}