// Program to implement stack in C

#include<stdio.h>
#include<conio.h>

int top = -1;
int stack[10];
int size;

void DisplayStack()
{
    printf("Elements in the stack: ");
    for (int i = 0; i <= top; i++)
    {
        printf(" %d", stack[i]);
    }
}

int Pop()
{
    if(top == -1)
    {
        return 0;
    }
    else
    {
        top--;
        return 1;
    }
}

int push(int val)
{
    if(top == -1)
    {
        top++;
        stack[top] = val;
        return 1;
    }
    else if(top + 1 == size)
    {   
        return 0;
    }
}

int main()
{
    int n, val;
    char choice;

    printf("Enter the size of the stack");
    scanf("%d", &size);    


    do
    {
        printf("Enter the operation you want to perform:\n1) Push\n2) Pop\n3) Display: ");
        scanf("%d", &n);

        switch (n)
        {
        case 1:
            printf("Enter the value you want to push into the stack: ");
            scanf("%d", val);
            n = push(val);

            if(n == 1)
                printf("%d pushed successfully", val);
            else
                printf("Stack is overflow");
            break;
        case 2:
            val = Pop();
            if (val == 0)
            {
                printf("Stack is underflow");
            }
            else
                printf("%d is poped successfully", val);
            break;
        case 3:
            DisplayStack();
            break;
        default:
            printf("Enter the correct option: ");
        }
        printf("Want to perform more operation:(press y or Y for yes) ");
        scanf("%s", &choice);
    }while(choice == 'y' || choice == 'Y');
}
