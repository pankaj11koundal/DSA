#include <iostream.>
#include <conio.h>

using namespace::std;

class Queue
{
private:
    int max;
    int front;
    int rear;
    int *arr;

public:
    Queue(int size)
    {
	max = size;
	front = -1;
	rear = -1;
	arr = new int[max];
    }

    int CheckStatus()
    {
	if (rear == max-1)
	{
	    return 0; // 0 for queue is overflow
	}
	else if ((rear == -1 && front == -1) || front > rear)
	{
	    return -1; // -1 for queue is underflow
	}
	else
	{
	    return 1; // 1 means can add more element in the queue
	}
    }

    void Insert()
    {
	int val;
	cout << "Enter the value you want to enter in the queue: ";



	
	cin >> val;
	if (CheckStatus() == 0)
	{
	    cout << "Queue is overflow";
	}
	else if (front == -1 && rear == -1)
	{
	    front += 1;
	    rear += 1;
	}
	else
	{
	    rear += 1;
	}
	arr[rear] = val;
    }

    void Delete()
    {
	if (CheckStatus() == -1)
	{
	    cout << "Queue is underflow";
	}
	else
	{	
		cout << arr;
	    int *ptr = arr;
	    front += 1;
		arr++;
		cout << arr;
	    cout << "Element deleted " << *ptr;
	    delete ptr;
	}
    }

    void ShowQueue(void)
    {
	for (int i = front; i <= rear; i++)
	{
	    cout << "Value at " << i  << " in the queue " << arr[i] << "\n";
	}
    }

    void FrontRear()
    {
	cout << "Element in the front is " << arr[front] << " and Element int the rear " << arr[rear];
    }
};

int main()
{
    int size, result, choose;
    char choice;
    cout << "Enter the maximum size of the queue: ";
    cin >> size;
    Queue Q(size);
    

    do
    {
	cout << "Choose the option from the below to perform the Stack operation: \n"
	     << "1) to enqueue\n"
	     << "2) to deque\n"
	     << "3) View Queue\n"
	     << "4) Check Status\n:";
	cin >> choose;
	cout << "\n";

	switch (choose)
	{
	case 1:
	    Q.Insert();
	    break;

	case 2:
	    Q.Delete();
	    break;

	case 3:
	    Q.ShowQueue();
	    break;

	case 4:
	    result = Q.CheckStatus();
	    if (result == 0)
	    {
		cout << "Stack is overflow ";
	    }
	    else if (result == -1)
	    {
		cout << "Queue is underflow ";
	    }
	    else
	    {
		cout << "You can perform any operation ";
	    }
	    break;
	default:
	    break;
	}
	cout << "\nWant to perform more operation: ";
	cin >> choice;
    } while (choice == 'Y' || choice == 'y');

    return 1;
    getch();
}