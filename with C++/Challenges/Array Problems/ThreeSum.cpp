#include<bits/stdc++.h>

using namespace std;

void merging(int arr[], int l, int mid, int r)
{
    int n1 = mid - l + 1, n2 = r - mid;
    int list1[n1];
    int list2[n2];
    int i, j, k;

    for (i = 0; i < n1; i++)
    {
        list1[i] = arr[l + i];
    }

    for (i = 0; i < n2; i++)
    {
        list2[i] = arr[mid + i + 1];
    }

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (list1[i] > list2[j])
        {
            arr[k] = list2[j];
            k++;
            j++;
        }
        else
        {
            arr[k] = list1[i];
            k++;
            i++;
        }
    }
    
    while (i < n1)
    {
        arr[k] = list1[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = list2[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int mid = (l + r) / 2; 
        mergeSort(arr, l, mid);
        mergeSort(arr, mid + 1, r);

        merging(arr, l, mid, r);
    }
    
}

bool threeSum(int arr[], int n, int givenSum)
{
    int sum, j, k;
    mergeSort(arr, 0, n - 1);

    for (int i = 0; i < n; i++)
    {
        sum = arr[i];
        j = i, k = n -1;
        while (j < k)
        {
            if (arr[j] + arr[k] == givenSum - sum)
            {
                cout << arr[i] << " " << arr[j] << " " << arr[k] << endl;
                return true;   
            }
            else if (arr[j] + arr[k] > givenSum - sum)
            {
                k--;
            }
            else
            {
                j++;
            }
        }
    }
    return false;
}

int main()
{
    int n, givenSum;
    cout << "Enter the size of the array: ";
    cin >> n;

    int arr[n];
    cout << "Enter the elements in the array: ";
    for (int  i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    
    cout << "Enter the given sum: ";
    cin >> givenSum;
    
    cout << threeSum(arr, n, givenSum);

    return 0;
}