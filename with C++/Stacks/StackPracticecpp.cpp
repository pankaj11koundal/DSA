#include<iostream>

using namespace::std;

// practice program to show the implementation of stack

class stack
{
private:
    int max;
    int top;
    int *arr;

public:
    stack(int size)
    {
        max = size;
        top = -1;
        arr = new int[max];
    }

    int checkstatus()
    {
        if (top + 1 == max)
        {
            return 1;
        }        
        else if (top == -1)
        {
            return -1;
        }
        else
        {
            return 0;
        }
        
    }

    int push()
    {
        int val;
        if (checkstatus() == 1)
        {
            cout << "Unable to operate the push operation, stack is overflow";
            return 1;
        }
        else
        {
            cout << "Enter the value you want to pust into the stack: ";
            cin >> val;
            top++ ;
            arr[top] = val;
            return 0;
        }
    }
        
    int pop()
    {
        if(checkstatus() == -1)
        {
            cout << "Unable to perform pop operation, stack is underflow";
            return 1;
        }
        else
        {
            top--;
            return 0;
        }
        
    }

    void viewstack()
    {
        if (checkstatus() == -1)
        {
            cout << "Nothing to display because stack is underflow. Enter some element first";
        }
        else
        {
            for (int i = 0; i <= top; i++)
            {
                cout << "Element at position " << i + 1 << " is " << arr[i];
                cout << "\n";
            }
            
        }
    }

    int peek()
    {
        return arr[top];
    }

};

int main()
{
    int size, op, result;
    char choice;
    cout << "Enter the size of the stack: ";
    cin >> size;
    stack s(size);

    do
    {
        cout << "Choose the operation from below:-\n"
             << "1) Push\n"
             << "2) Pop\n"
             << "3) viewstack\n"
             << "4) checkstatus:\n "
             << "5) peek: ";
        cin >> op;

        switch(op)
        {
            case 1:
                cout << "You choosed push operation\n";
                result = s.push();
                if (result)
                {
                    cout << "\nOperation push was unsuccessfull";
                }
                else
                {
                    cout << "Operation of push was successfull";
                }
                break;
                
            case 2:
                cout << "You choosed pop operation\n";
                result = s.pop();
                if (result)
                {
                    cout << "\nOperation of pop was unsuccessfull";
                }
                else
                {
                    cout << "Operation of pop was successfull";
                }
                break;

            case 3:
                s.viewstack();
                break;
            
            case 4:
                result = s.checkstatus();
                if (result == 1)
                {
                    cout << "Stack is overflow";
                }
                else if (result == -1)
                {
                    cout << "Stack is underflow";
                }
                else
                {
                    cout << "You can perform any operation";
                }
                break;

            case 5:
                cout << "Element at top of the stack is " << s.peek();
                break;
        }

        cout << "\nWant to perform more operation(y/n):";
        cin >> choice;
        cout << "\n";
    } while (choice == 'Y' || choice == 'y');
    
}