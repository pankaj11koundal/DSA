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

node* reverseKNodes(node* head, int k)
{
    node* prevptr = NULL;
    node* currptr = head;
    node* newptr;
    int count = 0;

    while(currptr != NULL && count < k)
    {
        newptr = currptr->next;
        currptr->next = prevptr;
        prevptr = currptr;
        currptr = newptr;
        count ++;
    }

    if(newptr != NULL)
        head->next = reverseKNodes(newptr, k);


    return prevptr;
}

int main()
{
    char choice;
    int k = 3;
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

    head = reverseKNodes(head, k);
    cout << "Elements of the list: ";
    traverse(head);
    cout << endl;
 
    return 0;
}