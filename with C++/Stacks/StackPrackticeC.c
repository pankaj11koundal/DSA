#include<stdio.h>

struct Stack
{
    int max;
    int top;
    int *arr;
};

int checkstatus(struct Stack s)
{
    if (s.top + 1 == s.max)
    {
        return 1;
    }        
    else if (s.top == -1)
    {
        return -1;
    }
    else
    {
        return 0;
    }
    
}

int push(struct Stack s)
{
    int val;
    if (checkstatus(s) == 1)
       {
        printf("Unable to operate the push operation, stack is overflow");
        return 1;
    }
    else
    {
        printf("Enter the value you want to pust into the stack: ");
        scanf("%d", &val);
        s.top++ ;
        s.arr[s.top] = val;
        return 0;
    }
}
        
int pop(struct Stack s)
{
    if(checkstatus(s) == -1)
    {
        printf("Unable to perform pop operation, stack is underflow");
        return 1;
    }
    else
    {
        s.top--;
        return 0;
    }
     
}

void viewstack(struct Stack s)
{
    if (checkstatus(s) == -1)
    {
        printf("Nothing to display because stack is underflow. Enter some element first");
    }
    else
    {
        for (int i = 0; i <= s.top; i++)
        {
            printf("Element at position %d is %d\n", i + 1,s.arr[i]);
        }
            
    }
}

int peek(struct Stack s)
{
    return s.arr[s.top];
}

int main()
{
    int size, op, result;
    char choice;
    printf("Enter the size of the stack: ");
    scanf("%d", size);
    struct Stack s; 
    s.max = size;

    do
    {
        printf("Choose the operation from below:-\n"
              "1) Push\n"
              "2) Pop\n"
              "3) viewstack\n"
              "4) checkstatus:\n "
              "5) peek: ");
        scanf("%s", op);

        switch(op)
        {
            case '1':
                printf("You choosed push operation\n");
                result = push(s);
                if (result)
                {
                    printf("\nOperation push was unsuccessfull");
                }
                else
                {
                    printf("Operation of push was successfull");
                }
                break;
                
            case '2':
                printf("You choosed pop operation\n");
                result = pop(s);
                if (result)
                {
                    printf("\nOperation of pop was unsuccessfull");
                }
                else
                {
                    printf("Operation of pop was successfull");
                }
                break;

            case '3':
                viewstack(s);
                break;
            
            case '4':
                result = checkstatus(s);
                if (result == 1)
                {
                    printf("Stack is overflow");
                }
                else if (result == -1)
                {
                    printf("Stack is underflow");
                }
                else
                {
                    printf("You can perform any operation");
                }
                break;

            case '5':
                printf("Element at top of the stack is %d", peek(s));
                break;
        }

        printf("\nWant to perform more operation(y/n): ");
        scanf( "%s\n", choice);
    } while (choice == 'Y' || choice == 'y');
    return 0;
}