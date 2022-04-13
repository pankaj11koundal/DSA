// Algorithm to perform Dutch name flag orr 123 sorting

#include<iostream>

using namespace std;

void dnfSort(int arr[], int n)
{
    int low = 0, mid = 0, high = n - 1, temp;

    while (mid <= high)
    {
        if (arr[mid] == 0)
        {
            temp = arr[mid];
            arr[mid] = arr[low];
            arr[low] = temp;

            mid++;
            low++;
        }

        else if (arr[mid] == 1)
        {
            mid++;
        }

        else 
        {
            temp = arr[mid];
            arr[mid] = arr[high];
            arr[high] = temp;

            high--;
        }
    }
}

int main()
{
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    int arr[n];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    dnfSort(arr, n);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    } 
}
