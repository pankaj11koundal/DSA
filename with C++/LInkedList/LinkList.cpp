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
    cout << "Enter the index number(Cannot be greater than the total number of nodes i.e.," << count << " : ";
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

Node *InsertNode(Node *head)
{
    int choice;
    Node *p = head;
    cout << "Choose any of the following insertion operation: "
         << "1)Insertion from the beginning\n"
         << "2)Insertion in between two nodes\n"
         << "3)Insertion at the end\n"
         << "4)Insertion after the given node.\n";
    cin >> choice;

    switch (choice)
    {
    case 1:
        head = InsertAtBeg(head);
        count++;
        return head;
    case 2:
        InsertBetweenTwo(head);
        count++;
        return head;
    case 3:
        InsertionAtEnd(head);
        count++;
        return head;
    case 4:
        int index;
        cout << "Enter the  number of node(Cannot be greater than the total number of nodes i.e.," << count << " : ";
        cin >> index;
        for (int i = 1; i < index - 1; i++)
        {
            p = p->next;
        }
        AddAfterAddress(p);
        return head;
    }
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

int main()
{
    clearerr;
    char choice = 'y';
    int choose = 1;
    cout << "Creating first node: \n";
    Node *head = new Node;
    head->giveval();
    cout << "Linked List before the Insertion of node:\n";
    TraversalList(head);
    
    do
    {
        head = InsertNode(head);
        cout << "Status after " << count << " insertion";
        cout << "\n";
        TraversalList(head);
        cout << "\nWant to add more nodes(Y/y): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    cout << "Linked list after insertion of node:\n";
    TraversalList(head);
    return 0;
    getch();
}
