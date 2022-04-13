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
        temp->next = temp;
        return temp;
    }
    
    while (ptr->next != head)
    {
        ptr = ptr->next;
    }

    temp->next = head;
    ptr->next = temp;
    return head;
}

node *insertAtHead(node *head)
{
    node *ptr = head, *temp = new node();
    temp->setData();

    if (head == NULL)
    {
        temp->next = temp;
        return temp;
    }

    while (ptr->next != head)
    {
        ptr = ptr->next;
    }
    
    ptr->next = temp;
    temp->next = head;
    return temp;
}

void deleteFromEnd(node *head)
{
    node *ptr = head;

    while (ptr->next->next != head)
    {
        ptr = ptr->next;
    }
    delete ptr->next;
    ptr->next = head;
}

node *deleteFromHead(node *head)
{
    node *ptr = head;

    while (ptr->next !=head)
    {
        ptr = ptr->next;
    }
    head = head->next;
    delete head;
    ptr->next = head;
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

     head = deleteFromHead(head);

    traverse(head);
}