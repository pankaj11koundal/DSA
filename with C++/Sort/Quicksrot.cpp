#include <iostream>
#include <conio.h>

using namespace ::std;

// Program to implement the Quick sort on a give list

int partition(int lb, int ub, int array[])
{
    int start = lb, end = ub, pivot, temp;
    pivot = array[lb];

    while (start < end)
    {
        while ((array[start] <= pivot) && (start <= ub))
        {
            start++;
        }

        while ((array[end] > pivot) && (end >= lb))
        {
            end--;
        }

        if (start < end)
        {
            temp = array[start];
            array[start] = array[end];
            array[end] = temp;
        }
    }

    temp = array[lb];
    array[lb] = array[end];
    array[end] = temp;         
    return end;
}

void QuickSort(int lb, int ub, int list[])
{ 
    int end;
    if (lb < ub)
    {
        end = partition(lb, ub, list);
        QuickSort(lb, end-1, list);
        QuickSort(end+1, ub, list);
    }
}

int main()
{
    int list[100], i, size;
    cout << "Enter the size of the array: ";
    cin >> size;

    cout << "Enter the elements in the array:\n";
    for (i = 0; i < size; i++)
    {
        cout << "Enter the element at position " << i + 1 << ": ";
        cin >> list[i];
    }

    cout << "Elements in the array before sorting:\n";
    for (i = 0; i < size; i++)
    {
        cout << "Element at address " << i + 1 << ": ";
        cout << list[i] << "\n";
    } 

    QuickSort(0, size-1, list);

    cout << "Elements in the array after sorting:\n ";
    for (i = 0; i < size; i++)
    {
        cout << "Element at address " << i + 1 << ": ";
        cout << list[i] << "\n";
    }
}