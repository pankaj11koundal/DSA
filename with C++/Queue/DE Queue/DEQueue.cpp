#include <stdio.h>
#include <iostream>

using namespace ::std;

// Program to show the implementation of Double Ended Queue

class DEQueue
{
private:
    int size;
    int front;
    int rear;
    int *arr;

public:
    DEQueue(int n)
    {
        size = n;
        front = -1;
        rear = -1;
        arr = new int[size];
    }

    int FrontInsertion(int val);
    int RearInsertion(int val);
    int RearDeletion();
    int FrontDeletion();
    void Display();
};

int DEQueue::FrontInsertion(int val)
{
    if (front == 0 && rear + 1 == size)
    {
        cout << "Insertion is not possible becaues Queue is already full";
        return 0;
    }
    else if (front == 0 && rear + 1 != size)
    {
        cout << "Insertion from this end is not possible";
        return 0;
    }
    else if (front == -1 && rear == -1)
    {
        front++;
        rear++;
    }
    else
    {
        front--;
    }
    arr[front] = val;
    return 1;
}

int DEQueue::RearInsertion(int val)
{
    if (front == 0 && rear + 1 == size)
    {
        cout << "Unable to insert, Queue is already full";
        return 0;
    }
    else if (rear + 1 == size && front != 0)
    {
        cout << "Unable to insert front this side";
        return 0;
    }
    else if (rear == -1 && front == -1)
    {
        front++;
        rear++;
    }
    else
    {
        rear++;
    }
    arr[rear] = val;
    return 1;
}

int DEQueue::FrontDeletion()
{
    if (front == -1 && rear == -1)
    {
        cout << "Unable to dequeue Because Queue is not empty";
        return 0;
    }
    else if (front == rear)
    {
        front = -1;
        rear = -1;
        return 1;
    }
    else
    {
        front++;
        return 1;
    }
}

int DEQueue::RearDeletion()
{
    if (front == -1 && rear == -1)
    {
        cout << "Unable to dequeue because queue is not empty";
        return 0;
    }
    else if (front == rear)
    {
        front = -1;
        rear = -1;
        return 1;
    }
    else
    {
        rear--;
        return 1;
    }
}

void DEQueue::Display()
{
    if (front == -1 && rear == -1)
    {
        cout << "Can't display Queue is empty";
    }
    else
    {
        cout << "Elements in the Queue: \n";
        for(int i = front; i <= rear; i++)
        {
            cout << "Elements at position " << i + 1 << " xis " << arr[i] << "\n";
        }
    }
    
} 

int main()
{
    int n, op, result, val;
    char choice;
    cout << "Enter the size of the Queue: ";
    cin >> n;
    DEQueue DQ(n);

    do
    {
        cout << "Choose the operation from the below:\n"
             << "1) Insertion from the front of Queue\n"
             << "2) Insertion from the rear of Queue\n"
             << "3) Deletion from the front of Queue\n"
             << "4) Deletion from the rear of Queue:\n"
             << "5) Display Queue: ";
        cin >> op;

        switch (op)
        {
        case 1:
            cout << "You choose Insertion from the front\n";
            cout << "Enter the value of the element: ";
            cin >> val;
            result = DQ.FrontInsertion(val);
            if (!result)
            {
                cout << "\nOperation failed";
            }
            else
            {
                cout << "\nQperation successfull";
            }
            break;
                        
        case 2:
            cout << "You choose Insertion from the rear\n";
            cout << "Enter the value of the element: ";
            cin >> val;
            result = DQ.RearInsertion(val);
            if (!result)
            {
                cout << "\nOperation failed";
            }
            else
            {
                cout << "\nQperation successfull";
            }
            break;
                   
        case 3:
            cout << "You choose Deletion from the front\n";
            result = DQ.FrontDeletion();
            if (!result)
            {
                cout << "\nOperation failed";
            }
            else
            {
                cout << "\nQperation successfull";
            }
            break;
        
        case 4:
            cout << "You choose Deletion from the rear\n";
            result = DQ.RearDeletion();
            if (!result)
            {
                cout << "\nOperation failed";
            }
            else
            {
                cout << "\nQperation successfull";
            }
            break;
        
        case 5:
            DQ.Display();
        }

        cout << "\nWant to perform more operation, press Y for yes and N for no(wrong choice result into no: )";
        cin >> choice;

    } while (choice == 'y' || choice == 'Y');
}