// C++ Program to append the K nodes in the beginning of the linked list

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
        return temp;
    }
    while(p->next != NULL)
    {
        p = p->next;
    }
    p->next = temp;
    return head;
}

int length(node *head)
{
    node *ptr = head;
    int count = 1;
    while(head->next != NULL)
    {
        head = head->next;
        count++;
    }
    return count;
}

node *appendKNodes(node *head, int k)
{
    node *tail = head;
    node *newTail;
    node *newHead;
    int count = 1, l = length(head);
    cout << l;
    while (tail->next != NULL)
    {
        if (count == l - k)
        {
            newTail = tail;
        }
        if(count == l - k + 1)
        {
            newHead = tail;
        }
        
        count++;
        tail = tail->next;
    }
    newTail->next = NULL;
    tail->next = head;
    return newHead;
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

    head = appendKNodes(head, k);
    cout << "Elements of the list: ";
    traverse(head);
    cout << endl;
 
    return 0;
}