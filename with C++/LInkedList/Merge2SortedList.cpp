#include<iostream>

using namespace std;

class node
{
    private:
        int data;

    public:

        node* next;

        node()
        {
            next = NULL;
        }
        void setData()
        {
            cout << "Enter the data in the node: ";
            cin >> data;
        }

        int getData()
        {
            return data;
        }
};

node* insertNode(node* head)
{
    node* p = head;
    node* temp = new node();
    temp->setData();

    if(head == NULL)
    {
        head = temp;
        return head;
    }
    while(p->next != NULL)
    {
        p = p->next;
    }
    p->next = temp;
    delete p;
    return head;
}

int length(node *head)
{
    node *ptr = head;
    int count = 1;
    while(ptr->next != NULL)
    {
        ptr = ptr->next;
        count++;
    }
    return count;
}

void traverse(node* head)
{
    node* p = head;
    while(p != NULL)
    {
        cout << p->getData();
        cout << " ";
        p = p->next;
    }
}

node *Merge2List(node *head1, node *head2)
{
    node *ptr1 = head1, *ptr2 = head2, *ptr3 = new node(), *newhead = ptr3;
    cout << "Entering data for the new list: " << endl;
    ptr3->setData();

    while (ptr1!= NULL && ptr2 != NULL)
    {
        if (ptr1->getData() < ptr2->getData())
        {
            ptr3->next = ptr1;
            ptr3 = ptr3->next;
            ptr1 = ptr1->next;
        }
        else
        {
            ptr3->next = ptr2;
            ptr3 = ptr3->next;
            ptr2 = ptr2->next;
        }
    }

    while (ptr2 != NULL)
    {
        ptr3->next = ptr2;
        ptr3 = ptr3->next;
        ptr2 = ptr2->next;
    }
    while (ptr1 != NULL)
    {
        ptr3->next = ptr1;
        ptr3 = ptr3->next;
        ptr1 = ptr1->next;
    }
    
    return newhead;
}

int main()
{
    char choice;
    node* head1 = NULL;
    node* head2 = NULL;
    node *newhead;

    cout << "Insert element in the 1st list: " << endl;
    do
    {
        head1 = insertNode(head1);
        cout << "Want to insert more nodes: ";
        cin >> choice;
    }while(choice == 'y' || choice == 'Y');

    cout << "Insert element in the 2nd list: " << endl;
    do
    {
        head2 = insertNode(head2);
        cout << "Want to insert more nodes: ";
        cin >> choice;
    }while(choice == 'y' || choice == 'Y');
 
    newhead = Merge2List(head1, head2);

    traverse(newhead);

    return 0;
}