// CPP program to find the intersection of nodes in two linked list

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
    return head;
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

void createIntersection(node *head1, node *head2, int k)
{
    node *ptr1 = head1, *ptr2 = head2;
    while (k)
    {
        ptr1 = ptr1->next;
        k--;
    }

    while (ptr2->next != NULL)
    {
        ptr2 = ptr2->next;
    }

    ptr2->next = ptr1;
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

bool detectIntersection(node *head1, node *head2)
{
    node *ptr1;
    node *ptr2;
    int l1 = length(head1);
    int l2 = length(head2);

    int d;
    if (l1 > l2)
    {
        d = l1 - l2;
        ptr1 = head1;
        ptr2 = head2;
    }
    else
    {
        d = l2 - l1;
        ptr1 = head2;
        ptr2 = head1;
    }
    
    while (d)
    {
        ptr1 = ptr1->next;
        d--;
    }
    

    while (ptr1 != NULL & ptr2 != NULL)
    {
        if(ptr1 == ptr2)
        {
            return 1;
        }
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    return 0;
}

int main()
{
    char choice;
    int k = 3;
    node* head1 = NULL;
    node* head2 = NULL;

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

    // cout << "Elements of the list: ";
    createIntersection(head1, head2, 3);
    traverse(head1);
    cout << endl;
    traverse(head2);
    cout << endl;

    cout << detectIntersection(head1, head2);
 
    return 0;
}
