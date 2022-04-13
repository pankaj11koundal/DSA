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


node *reverseList(node *head)
{
    if(head == NULL)
    {
        return insertNode(head);
    }

    node* prevptr = NULL;
    node* currptr = head;
    node* nextptr;

    while(currptr != NULL)
    {
        nextptr = currptr->next;
        currptr->next = prevptr;
        prevptr = currptr;
        currptr = nextptr;
    } 

    return prevptr;   
}

node* reverseRecursiveLinkedList(node* head)
{
    if(head == NULL || head->next == NULL)
    {
        return head;
    }

    node* newhead = reverseRecursiveLinkedList(head->next);
    head->next->next = head;
    head->next = NULL;
    return newhead;
}

int main()
{
    char choice;
    node* head = NULL;

    do
    {
        head = insertNode(head);
        cout << "Want to insert more nodes: ";
        cin >> choice;
    }while(choice == 'y' || choice == 'Y');

    cout << "Elements of the list: ";
    traverse(head);
    cout << endl;

    head = reverseList(head);
    cout << "Elements of the list";
    traverse(head);
    cout << endl;

    head = reverseRecursiveLinkedList(head);
    cout << "Elements of the list: ";
    traverse(head);


    return 0;
}