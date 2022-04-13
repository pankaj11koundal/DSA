#include <iostream>
#include <conio.h>

using namespace ::std;

// Program to show implementaion of queue and its operation on it

class Queue
{
private:
    int size;
    int rear;
    int front;
    int *arr;

public:
    Queue(int n)
    {
        size = n;
        rear = -1;
        front = -1;
        arr = new int[size];
    }

    int IsFull()
    {
        if (rear == size)
            return 1;
        else
            return 0;
    }

    int IsEmpty()
    {
        if (front == rear + 1)
            return 1;
        else
        return 0;
    }

    int Enqueue(int val)
    {
        if (IsFull())
        {
            cout << "Unable to enqueue more elements, queue is already full";
            return -1;
        }
        else if (rear == -1 && front == -1)
        {
            rear = 0;
            front = 0;
        }
        else
        {
            rear += 1;
        }

        arr[rear] = val;
    }

    int Dequeue()
    {
        if (IsEmpty())
        {
            cout << "Can't enqueue more element, Queue is underflow";
            return -1;
        }
        else
        {
            front++;
        }
    }

    int ShowQueue()
    {
        cout << "Elements in the queue\n";
        for (int i = front; i <= rear; i++)
        {
            cout << "Value at position " << i + 1 << " is " << arr[i] << "\n";
        }
    }
};

int main()
{

    int size, val, op, result = 1;
    cout << "Enter the size for your queue";
    cin >> size;
    Queue q(size - 1);
    char choice;

    do
    {
        cout << "Please choose any of the following operation- \n"
             << "1) Enqueue\n"
             << "2) Dequeue\n"
             << "3) to see elements\n"
             << "0) To exit:\n";
        cin >> op;

        switch (op)
        {
        case 1:
            cout << "You choosed enqueue operation, Enter the value you want to enqueue: ";
            cin >> val;
            result = q.Enqueue(val);
            if (result == -1)
            {
                cout << "\nTried operation failed";
            }
            else
            {
                cout << "\nOperartion is successfull";
            }
            break;
        case 2:
            cout << "You choosed dequeue operation: ";
            result = q.Dequeue();
            if (result == -1)
            {
                cout << "\nTried operation failed";
            }
            else
            {
                cout << "\nOperartion is successfull";
            }
            break;
        case 3:
            q.ShowQueue();
            break;
        default:
            break;
        }

        cout << "\nWant to perform again: ";
        cin >> choice;

    } while (choice == 'Y' || choice == 'y');

    return 0;
}