#include <stdio.h>
#include <conio.h>

int size, front = -1, rear = -1, queue[100];

int Enqueue(int val)
{
  if (rear + 1 == size)
  {
    printf("Stack overflow\n");
    return 0;
  }
  else if(rear = -1 && front == -1)
    {
      rear = 0;
      front = 0;
    }
  else
  {

    rear++;
  }
  queue[rear] = val;
  return val;
}

int Dequeue()
{
  int val;
  if (front == -1 && rear == -1)
  {
    printf("Queue is underflow");
    return 0;
  }
  else if (front == rear)
  {
    front = -1;
    rear = -1;
  }
  else
  {
    val = queue[front];
    front++;
  }
  return val;
}

void DisplayQueue()
{
  int i;
  printf("Elements in the queue: \n");
  for (i = 0; i <= rear; i++)
  {
    printf("%d ", queue[i]);
  }
  printf("\n");
}

int main()
{
  int n, val;
  char choice = 'y';
  // clrscr();

  printf("Enter the size of the queue: ");
  scanf("%d", &size);

  do
  {
    printf("Choose the operation you want to perform:-\n");
    printf("1) Enqueue\n");
    printf("2) Dequeue\n");
    printf("3) Display Queue\n");
    printf("4) Exit: ");
    scanf("%d", &n);

    switch (n)
    {
    case 1:
      printf("Enter the value of the element you want to enter in the queue: ");
      scanf("%d", &val);
      val = Enqueue(val);
      if (val)
        printf("%d enqueued successfully\n", val);
      else
        printf("Enqueuing of %d unsuccessful\n", val);
      break;

    case 2:
      n = Dequeue();
      if (n)
        printf("Dequeue of %d is successfull\n", n);
      else
        printf("Dequeuing of %d is unsuccessfull\n", n);
      break;

    case 3:
      DisplayQueue();
      break;

    case 4:
      choice == 'n';
      break;

    default:
      printf("Enter the correct option");
    }

  } while (choice == 'y' || choice == 'Y');
  return 0;
}