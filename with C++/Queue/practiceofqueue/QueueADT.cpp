#include<iostream>

using namespace::std;

class Queue
{
private:
    int size;
    int front;
    int rear;
    int *arr;

public:
    Queue(int max)
    {
        size = max;
        front = -1;
        rear = -1;
        arr = new int[size];
    }

    int Enqueue()
    {
        int val;
        if (rear + 1 == size)
        {
            cout << "Enqueue is not possible, Queue is full";
            return 1;
        }
        else if (rear == -1 && front == -1)
        {
            rear = 0;
            front = 0;
        }
        else
        {
            rear++ ;
        }
        cout << "Enter the element you want to Enqueue: ";
        cin >> val;
        arr[rear] = val;
        return 0;
    }

    int Dequeue()
    {
        if (rear == -1 && front == -1)
        {
            cout << "Unable to Dequeue, Queue is empty";
            return 1;
        }
        else if (front == rear)
        {
            rear = -1;
            front = -1;
        }
        else
        {
            front++;
        }
        return 0;
    }

    void Display()
    {
        if (rear == -1 && front == -1)
        {
            cout << "Nothing to display, Queue is empty\n";
        }
        else
        {
            for (int i = front; i <= rear; i++)
            {
                cout << "Element at position " << i + 1 << " is " << arr[i] << "\n";
            }
        }
    }    
};


int main()
{
    int size, result, op;

    cout << "Enter the size of the Queue: ";
    cin >> size;
    Queue Q(size);

    while(1)
    {
        cout << "Choose the option from the below: \n"
             << "1) Enqueue \n"
             << "2) Dequeue \n"
             << "3) Display \n"
             << "4) Exit: ";
        cin >> op;

        switch(op)
        {
            case 1:
                cout << "You choosed Enqueue operation\n";
                result = Q.Enqueue();
                if (result)
                {
                    cout << "\nEnqueue opertion failed\n";
                }
                else
                {
                    cout << "Enqueue opertion successfull\n";
                }
                break;
            
            case 2:
                cout << "You choosed Dequeue operation\n";
                result = Q.Dequeue();
                if (result)
                {
                    cout << "\nDequeue operation failed\n";
                }
                else
                {
                    cout << "\nDequeue operation successfull\n";
                }
                break;

            case 3:
                Q.Display();
                break;

            case 4:
                exit(1);
                break;

            default:
                cout << "\nWrong selecion of the option\n"; 
        }
    }
}