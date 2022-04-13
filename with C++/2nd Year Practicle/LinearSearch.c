#include<stdio.h>
#include<conio.h>

int main()
{
    int list[100], n, search, f = 0,i = 0;

    printf("Enter the size of the list: ");
    scanf("%d", &n);

    printf("Enter the elements in the list: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &list[i]);
    }
    
    printf("Enter the element you want to search in the list: ");
    scanf("%d", &search);

    for(i = 0; i < n; i++) 
    {
        if( search == list[i])
        {
            f = 1;
            break;
        }
    }

    if(f == 1)
        printf("The element found at %d", i + 1);
    else
        printf("Element not found in the list");
    return 0;
}