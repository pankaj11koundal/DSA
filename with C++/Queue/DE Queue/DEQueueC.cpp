#include <iostream>
#include <conio.h>

using namespace ::std;

// Program to show the implementation of double ended queue using an circular array

class CircularDEqueue
{
private:
    int size;
    int front;
    int rear;
    int *arr;

public:
    CircularDEqueue(int n)
    {
        size = n;
        front = -1;
        rear = -1;
        arr = new int[size];
    }

    int EnqueueFront(int val)
    {
        if ((front == 0 && rear + 1 == size) || (rear + 1 == front))
        {
            cout << "Unable to enqueue Queue is full";
            return 1;
        }
        else if (front == -1 && rear == -1)
        {
            front++;
            rear++;
        }
        else if (front == 0)
        {
            front = size - 1;
        }
        else
        {
            front--;
        }
        arr[front] = val;
        return 0;
    }

    int EnqueueRear(int val)
    {
        if ((front == 0 && rear + 1 == size) || (rear + 1 == front))
        {
            cout << "Unable to enqueue Queue is full";
            return -1;
        }
        else if (front == -1 && rear == -1)
        {
            front++;
            rear++;
        }
        else if (rear == size - 1)
        {
            rear = 0;
        }
        else
        {
            rear++;
        }
        arr[rear] = val;
        
        return 0;
    }

    int DequeueFront()
    {
        if (front == -1 && rear == -1)
        {
            cout << "Unable to dequeue, Queue is empty";
            return 1;
        }
        else if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else if (front == size - 1)
        {
            front = 0;
        }
        else
        {
            front++;
        }
        return 0;
    }

    int DequeueRear()
    {
        if (front == -1 && rear == -1)
        {
            cout << "Unable to dequeue, Queue is empty";
            return 1;
        }
        else if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else if (rear == 0)
        {
            rear = size - 1;
        }
        else
        {
            rear--;
        }
        return 0;
    }

    void Display()
    {
        int i = front;
        if (front == -1 && rear == -1)
        {
            cout << "Equeue is empty nothing to show...";
        }
        else
        {
            while (i != rear)
            {
                cout << "Element at position " << i + 1 << " is " << arr[i] << "\n";
                i = (i + 1) % size;
                cout << rear << "\n";
                cout << front;
            }
            cout << "Element at position " << i + 1 << " is " << arr[i];
        }
    }
};

int main()
{
    int op, size, val, result;
    char choice;
    cout << "Enter the size of the Queue";
    cin >> size;
    CircularDEqueue CDEq(size);

    do
    {
        cout << "Chosse the option form the below:\n"
             << "1) Enqueue from front \n"
             << "2) Enqueue form rear \n"
             << "3) Dequeue from front \n"
             << "4) Dequeue from rear \n"
             << "5) Display Queue: ";
        cin >> op;

        switch (op)
        {
        case 1:
            cout << "You choose Enqueue form front\n";
            cout << "Enter the value you want to enqueue: ";
            cin >> val;
            result = CDEq.EnqueueFront(val);
            if (result)
            {
                cout << "\nEnqueue from front operation failed";
            }
            else
            {
                cout << "Enqueue from front opertation successfull";
            }
            break;
        case 2:
            cout << "You choose Enqueue form rear\n";
            cout << "Enter the value you want to enqueue: ";
            cin >> val;
            result = CDEq.EnqueueRear(val);
            if (result)
            {
                cout << "\nEnqueue from front operation failed";
            }
            else
            {
                cout << "\nEnqueue from front opertation successfull";
            }
            break;
        case 3:
            cout << "You choose Dequeue from front ";
            result = CDEq.DequeueFront();
            if (result)
            {
                cout << "Dequeue from front operation failed";
            }
            else
            {
                cout << "Dequeue from front operation successfull";
            }
            break;

        case 4:
            cout << "You choose Dequeue from rear ";
            result = CDEq.DequeueRear();
            if (result)
            {
                cout << "Dequeue from front operation failed";
            }
            else
            {
                cout << "Dequeue from rear operation  successfull";
            }
            break;
        case 5:
            CDEq.Display();
        }

        cout << "\nWant to perform more operation(y/n), Wrong choice resutl into exit of program: ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');
}