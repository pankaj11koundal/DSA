// Putting the even node after the odd nodes

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

node *insertAtEnd(node *head)
{
    node *ptr = head, *temp = new node();
    temp->setData(); 

    if (head == NULL)
    {
        return temp;
    }
    
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }

    ptr->next = temp;
    return head;
}

void traverse(node* head)
{
    node *p = head;
    while (p != NULL)
    {
        cout << p->getData() << "->";
        p = p->next;
    }
    cout << "NULL";
}

void evenAfterOdd(node *head)
{
    node *odd = head;
    node *even = head->next;
    node *evenStart = even;

    while (odd->next != NULL && even->next != NULL)
    {
        odd->next = even->next;
        odd = odd->next;
        even->next = odd->next;
        even = even->next;
    }

    odd->next = evenStart;
    if (odd->next != NULL)
    {
        even->next = NULL;
    }
}

int main()
{
    char choice;
    node* head = NULL;

    do
    {
        head = insertAtEnd(head);
        cout << "Want to insert more nodes: ";
        cin >> choice;
    }while(choice == 'y' || choice == 'Y');

    traverse(head);
    evenAfterOdd(head);
    cout << endl;
    traverse(head);
}