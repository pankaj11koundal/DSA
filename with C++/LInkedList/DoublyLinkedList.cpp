// Program to implement the working of insertion and deletion in doubly linked list

#include <iostream>

using namespace std;

class node
{
private:
    int data;

public:
    node *next;
    node *prev;

    node()
    {
        next = NULL;
        prev = NULL;
    }

    void setData()
    {
        cout << "Enter the data for the node: ";
        cin >> data;
    }

    int getData()
    {
        return data;
    }
};

node *insertFromTail(node *head)
{
    node *ptr = head;
    node *temp = new node();
    temp->setData();

    if (head == NULL)
    {
        return temp;
    }

    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }

    temp->prev = ptr;
    ptr->next= temp;
    return head;
}

node *insertFromHead(node *head)
{
    node *ptr = head;
    node *temp = new node();
    temp->setData();

    if (head == NULL)
    {
        return temp;
    }

    temp->next = head;
    head->prev = temp;
    head = temp;
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
    p = head;
}

void traverseFromTail(node *head)
{
    node *p = head;
    while(p->next !=NULL)
    {
        p = p->next;
    }
    while (p != NULL)
    {
        cout << p->getData() << " ";
        p = p->prev;
    } 
}

int main()
{
    node *head = NULL;
    char choice;
    do
    {
        head = insertFromHead(head);
        cout << "Want to enter more nodes: ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');
    

    cout << "Nodes in the linked list: ";
    traverse(head);

    cout << endl << "Traversing in the reverse order: ";
    traverseFromTail(head);

    return 0;
}