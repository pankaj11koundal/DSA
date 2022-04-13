#include<iostream.h>
#include<conio.h>

int Insertion(int a[],int size,int max)     /* Fuction to insert and element
						 into the array*/

{
 int element, index;
 cout<<"Enter the element your want to insert: ";
 cin>>element;
 cout<<"Enter the position where you want to insert: ";
 cin>>index ;
 if (index > max)
 {
  return -0;
 }
 else
 {
  int i;
  for(i=size;i>=index;i--)
  {
   a[i+1] = a[i];
  }
  a[index] = element;
  return 1;
 }
}

int Deletion(int a[],int size, int max)       /*Function to delete an element
						    from the array*/
{
 int index;
 cout<<"Enter the position where you want to delete an element: ";
 cin>>index;
 if (index > max)
 {
  return 0;
 }
 else
 {
  for(int i=index;i<size;i++)
  {
   a[i] = a[i+1];
  }
  return -1;
 }
}

void main()                              // main function
{
 clrscr();
 int a[100], n, result, choice, max = 100;

 cout<<"Enter the number of elements of your array: ";
 cin>>n;                              // getting number of elements for array

 cout<<"Enter the elements of your array: ";
 for(int i=0; i<n; i++)            // loop to enter elements in the array
 {
  cin>>a[i];
 }

 cout<<"Please choose any option from the below to execute the corresponding operation:"
     <<"1) Insertion"
     <<"2) Deletion"
     <<"Wrong choice result into end of execution: ";
 cin>>choice;

 switch(choice)          //Switch block to execute particular choosed funcion
 {
  case 1: result =  Insertion(a, n-1,max);
	  break;

  case 2: result = Deletion(a, n-1, max );
	  break;

  default: result = 0;
	   break;
  }

 if(result == -1)                  /* if else if statement to print success
				      whether the program is successful or not*/
 {
  cout<<"Deletion was successful";
  n -= 1;
 }
 else if(result == 0)
 {
  cout<<"Operation was unsuccessful";
 }
 else
 {
  cout<<"Insertion was successful";
  n += 1;
 }
 cout<<"\nElements in the array are:";

 for(i=0; i<n; i++)   // Loop to print all the elements after the operation
 {
  cout<<a[i]<<" ";
 }
 getch();

}
