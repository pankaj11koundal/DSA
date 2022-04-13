#include<stdio.h>
#include<conio.h>

int main()
{
    int n, list[100], search, start = 0, end, mid, f = 0;

    printf("Enter the size of the list: ");
    scanf("%d", &n);

    printf("Enter the elements in the list: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", list[i]);
    }

    printf("Enter the element you want to search in the list: ");
    scanf("%d", &search);

    end = n-1;

    while(start <= end)
    {
        mid = (start + end) / 2;
        if(list[mid] == search)
        {
            f == 1;
            break;
        }
        if (search < list[mid])
        {
            end = mid - 1;
        }
        else if(search > list[mid])
        {
            start = mid + 1;
        }
    }    

    if (f == 1)
    {
        printf("Element found at %d", mid + 1);
    }
    else
        printf("Element not found");
    return 0;   
}