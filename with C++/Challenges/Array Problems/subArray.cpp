// To print all the subarrays from an array of size of n

#include<iostream>

using namespace std;

int main()
{
    int n;
    
    cout << "Enter the size of array: ";
    cin >> n;

    int a[n];
    
    cout << "Enter the elements in the array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        { 
            int l = j;
            for (int k = i; k <= j; k++)
            {
                cout << a[k]<<" ";
            }
            cout << "\n";
        }   
        cout << "\n";
    }
}
