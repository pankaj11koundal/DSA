#include<iostream>
#include<conio.h>

using namespace std;

class Node
{
    private: int data;

    public: void giveval()
            {
                cout<<"enter the value : ";
                cin>>data;
            }

            void getval()
            {
                cout<<"The value is: "<<data<<"\n";
            }


            Node *next = NULL;
};

void InsertBetweenTwo(Node *head)
{
    int index;
    cout<<"Enter the index number(Cannot be greater than the total number of nodes): ";
    cin>>index;
    Node *ptr = new(Node);
    ptr->giveval();
    Node *p = head;
    for(int i=1; i < index-1; i++)
    {
        p = p-> next;
    }
    ptr->next = p->next;
    p->next = ptr;
}

void main()
{
    *head = new Node
}