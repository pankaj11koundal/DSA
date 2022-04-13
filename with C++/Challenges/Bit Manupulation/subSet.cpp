// To print the subset of an array using the bit manuplation 

#include<iostream>

using namespace std;

int main()
{
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    int arr[n];
    cout << "Enter the elements in the array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    for (int i = 0; i < (1 << n); i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(i & (1 << j))
            cout << arr[j] << " ";
        }
        cout << endl;
    }

    return 0;    
}
