#include <iostream>
#include <conio.h>

using namespace ::std;

// Program to show the implementation of Circular Array as ADT

class CircularQueue
{
private:
    int size;
    int front;
    int rear;
    int *arr;

public:
    CircularQueue(int n)
    {
        size = n;
        front = -1;
        rear = -1;
        arr = new int[size];
    }

    int Enqueue(int val)
    {
        if ((rear + 1) % size == front)
        {
            cout << "Unable to enqueue, because Queue is full";
            return 1;
        }
        else if (rear == -1 && front == -1)
        {
            rear += 1;
            front += 1;
        }
        else
        {
            rear = (rear + 1) % size;
        }
        arr[rear] = val;
        cout << "Element at position " << rear + 1 << " is enqueued with value " << val;
        cout << "\n position of rear and front: " << rear << " and " << front << "\n";
        return 0;
    }

    int Dequeue()
    {
        if (front == -1 && rear == -1)
        {
            cout << "Unable Dequeue, because Queue is empty";
            return 1;
        }
        else if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            front = (front + 1) % size;
        }
        cout << "Element at position " << front - 1 << "dequeued successfully";
        cout << "\n position of rear and front: " << rear << " and " << front << "\n";
        return 0;
    }

    void display()
    {
        int i;
        if (front == -1 && rear == -1)
        {
            cout << "Nothing to display because queue is empty";
        }
        else
        {
            for (i = front; (i + 1) % size != front; i = (i + 1) % size)
            {
                if (i == rear)
                {
                    break;
                }
                    cout << "Value at position " << i + 1 << " is " << arr[i];
                    cout << "\n";
            }
        cout << "Value at position " << i + 1 << " is " << arr[i];
        cout << "\n";
        }
        
    }
};

int main()
{
    int op, result = 0, size, val;
    char choice;
    cout << "Enter the size of the Queue: ";
    cin >> size;
    CircularQueue Cq(size);

    do
    {
        cout << "Choose any option from the below:\n"
             << "1. Enqueue\n"
             << "2. Dequeue\n"
             << "3. Display Queue: ";
        cin >> op;

        switch (op)
        {
        case 1:
            cout << "You choose Enqueue";
            cout << "\nEnter the element you want to enqueue: ";
            cin >> val;
            result = Cq.Enqueue(val);
            if (result)
            {
                cout << "\nEnqueue of element was unsuccessfull\n";
            }
            break;

        case 2:
            cout << "You choose Dequeue\n";
            result = Cq.Dequeue();
            if (result)
            {
                cout << "\nDequeue of element was unsuccessfull\n";
            }
            break;

        case 3:
            Cq.display();
            break;
        }

        cout << "Want to perform more operation (y/n): ";
        cin >> choice;
    } while (choice == 'Y' || choice == 'y');
}