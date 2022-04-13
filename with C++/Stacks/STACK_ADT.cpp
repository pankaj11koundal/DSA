#include <iostream>
#include <conio.h>

using namespace ::std;

class Stack
{
private:
    int max = 5;
    int top;
    int *arr;

public:
    Stack(int size)
    {
        top = -1;
        arr = new int[size];
    }

    void push()
    {
        int val;
        top++;
        if (top == max)
        {
            cout << "Stack is overflow please delete some elements form the stack";
        }
        else
        {
            cout << "Pushing the values in the stack:\n";
            cout << "Please enter the value which you want to push into the stack\n";
            cin >> val;
            arr[top] = val;
            cout << val << " is pushed into the stack at "<<"\n";
            cout << "*****************************************************************";
            cout << "***********************************************************************";
        }
    }

    void viewstack()
    {
        if (top == -1)
        {
            cout << "Stack is underflow, please push some elements in the stack first.";
        }
        else
        {
            {
                for (int i = 0; i < top; i++)
                    cout << "Value at position at " << i + 1 << " is " << arr[i] << "\n";
            }
        }
    }

    void pop()
    {
        if (top == -1)
        {
            cout << "Stack is underflow, please push some elements first to pop";
        }
        else
        {
            delete (arr + (sizeof(int) * (top)));
            top--;
            cout << "One item deleted";
        }
    }

    void checkstatus()
    {
        if (top == -1)
        {
            cout << "Stack is underflow";
        }
        else if (top == max)
        {
            cout << "Stack is overflow";
        }
        else
        {
            cout<<"You can add more elements in the stack";
        }
        
    }
};

int main()
{
    Stack s(10);
    int choose;
    char choice;

    do
    {
        cout << "Choose the option from the below to perform the Stack operation: \n"
             << "1) Push\n"
             << "2) Pop\n"
             << "3) View Stack\n"
             << "4) Check Status\n:";
        cin >> choose;
        cout<<"\n";

        switch (choose)
        {
        case 1:
            s.push();
            break;

        case 2:
            s.pop();
            break;

        case 3:
            s.viewstack();
            break;

        case 4:
            s.checkstatus();
            break;
        default:
            break;
        }
        cout << "\nWant to perform more operation: ";
        cin >> choice;
    } while (choice == 'Y' || choice == 'y');

    return 1;
}