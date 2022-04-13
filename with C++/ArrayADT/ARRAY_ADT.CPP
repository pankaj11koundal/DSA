#include<iostream.h>
#include<conio.h>

class array
{
 private : int sa;
	   int sr;
	   int *ptr, *rptr;

 public  : array(int p, int q)
	   {
	    sa = p;
	    sr = q;
	    ptr = new int[sa];
	   }

	   void set(int i, int value)
	   {
	    *(ptr+(i*sizeof(int))) = value;
	   }

	   int get(int i)
	   {
	    return *(ptr + (i*sizeof(int)));
	   }

	   void givevals();

	   void getvals();

	   void resize(int);
};

void array :: givevals()
{
 for(int i=0; i<sr; i++)
 {
  cout<<"Enter the value a t "<<i+1<<" position: ";
  cin>>*(ptr+(i*sizeof(int)));
 }
}

void array :: getvals()
{
 for(int i=0; i<sr; i++)
 {
  cout<<*(ptr+(i*sizeof(int)))<<" ";
 }
}

void array :: resize(int size)
{
 rptr = new int[sr];
 for (int i=0; i<sr; i++)
 {
  *(rptr+(i*sizeof(int))) = *ptr;
  ptr++;
 }

 for (; i<size; i++)
 {
  cout<<"Enter the value at "<< i+1<<": ";
  cin>>*(rptr+(i*sizeof(int)));
 }
 sr = size;
 ptr = rptr;
 delete rptr;
}


void main()
{
 clrscr();
 int p,q,val,i;
 cout<<"Enter the space you want to make available ";
 cin>>p;
 cout<<"Enter the space required by you ";
 cin>>q;
 array arr(p,q);
 cout<<"Enter the values in your array:\n";
 arr.givevals();
 cout<<"The values in your string is \n";
 arr.getvals();
 cout<<"\nEnter the value you want to change in the array: ";
 cin>>val;
 cout<<"\nEnter the position you want to change: ";
 cin>>i;
 arr.set(i, val);
 cout<<"\nValues in the array after the changes: \n";
 arr.getvals();
 cout<<"\nEnter the index no. whose value you want to enter: ";
 cin>>i;
 cout<<arr.get(i);
 cout<<"\nEnter the size you want for your array: ";
 cin>>q;
 arr.resize(q);
 cout<<"\n";
 arr.getvals();
 getch();
}
