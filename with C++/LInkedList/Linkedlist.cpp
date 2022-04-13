#include <iostream>
#include <conio.h>

using namespace std;

class Node
{
private:
    int data;

public:
    void giveval()
    {
        cout << "enter the value : ";
        cin >> data;
    }

    void getval()
    {
        cout << "The value is: " << data << "\n";
    }
    Node *next = NULL;
};

int count = 1;

Node *InsertAtBeg(Node *head)
{
    Node *ptr = new Node;
    ptr->giveval();
    ptr->next = head;
    return ptr;
}

void InsertBetweenTwo(Node *head)
{
    int index;
    cout << "Enter the index number(Cannot be greater than the total number of nodes i.e.," << count << " ): ";
    cin >> index;
    Node *ptr = new Node;
    ptr->giveval();
    Node *p = head;
    for (int i = 1; i < index - 1; i++)
    {
        p = p->next;
    }
    ptr->next = p->next;
    p->next = ptr;
}

void InsertionAtEnd(Node *head)
{
    Node *p = head;
    Node *ptr = new Node;
    ptr->giveval();
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = ptr;
}

void AddAfterAddress(Node *p)
{
    Node *ptr = new Node;
    ptr->giveval();
    ptr->next = p->next;
    p->next = ptr;
}

Node *DeleteAtBeg(Node *head)
{
    Node *ptr = head;
    head = head->next;
    delete ptr;
    return head;
}

void DeleteBetweenTwo(Node *head)
{
    int index;
    cout << "Enter the index number(Cannot be greater than the total number of nodes i.e.," << count << " : ";
    cin >> index;
    Node *p = head;
    for (int i = 1; i < index-1; i++)
    {
        p = p->next;
    }
    Node *q = p->next;
    p->next = q->next;
    delete q;
}

void DeleteAtEnd(Node *head)
{
    Node *p = head;
    Node *q = p->next;
    while (q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }
    p->next = NULL;
    delete q;
}

void DeleteAfterAddress(Node *p)
{
    Node *q = p->next;
    p->next = q->next;
    delete q;
}

void TraversalList(Node *head)
{
    Node *ptr = head;
    while (ptr != NULL)
    {
        ptr->getval();
        ptr = ptr->next;
    }
}

Node *InsertNode(Node *head)
{
    int choice;
    Node *p = head;
    cout << "Choose any of the following insertion operation:\n"
         << "1)Insertion from the beginning\n"
         << "2)Insertion in between two nodes\n"
         << "3)Insertion at the end\n"
         << "4)Insertion after the given node: \n";
    cin >> choice;

    switch (choice)
    {
    case 1:
        head = InsertAtBeg(head);
        count++;
        break;
    case 2:
        InsertBetweenTwo(head);
        count++;
        break;
    case 3:
        InsertionAtEnd(head);
        count++;
        break;
    case 4:
        int index;
        cout << "Enter the  number of node(Cannot be greater than the total number of nodes i.e.," << count << " : ";
        cin >> index;
        for (int i = 1; i < index - 1; i++)
        {
            p = p->next;
        }
        AddAfterAddress(p);
    }
    cout << "Linked List after Insertion: \n";
    TraversalList(head);
    return head;
}

Node *DeleteNode(Node *head)
{
    Node *p = head;
    int choice;
    cout << "Choose any of the following Deletion operation:\n"
         << "1)Deletion from the beginning\n"
         << "2)Deletion in between two nodes\n"
         << "3)Deletion at the end\n"
         << "4)Deletion after the given node.: \n";
    
    cin >> choice;
    switch (choice)
    {
    case 1:
        head = DeleteAtBeg(head);
        count--;
        cout << "Delete from beginning is successful";
        break;
    case 2:
        DeleteBetweenTwo(head);
        count--;
        break; 
    case 3:
        DeleteAtEnd(head);
        count--;
        break;
    case 4:
        int index;
        cout << "Enter the  number of node(Cannot be greater than the total number of nodes i.e.," << count << " : ";
        cin >> index;
        for (int i = 1; i < index - 1; i++)
        {
            p = p->next;
        }
        DeleteAfterAddress(p);
        count--;
    }
    cout << "Linked List after deletion:\n";
    TraversalList(head);
    return head;
}

int ChooseOperation()
{
    int choose;
    cout << "Choose the option below\n"
         << "1) Insertion\n"
         << "2) Deletion\n"
         << "Wrong choice result into exit: ";
    cin >> choose;
    return choose;
}

int main()
{
    clearerr;
    char choice = 'y';
    int choose;
    Node *head = new Node;
    head->giveval();

    do
    {
        choose = ChooseOperation();
        switch (choose)
        {
        case 1:
            head = InsertNode(head);
            break;
        case 2:
            head = DeleteNode(head);
            break;
        default:
            break;
        }
        cout << "Want to perform more operation(y for yes and n for no): ";
        cin >> choice;
    } while (choice == 'Y' || choice == 'y');
    cout<<"Link list after operations: \n";
    TraversalList(head);
    return 0;
    getch();
}
