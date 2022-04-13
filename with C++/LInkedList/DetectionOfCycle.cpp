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

void createCycle(node *head, int k)
{
    node* temp;
    node* ptr = head;
    int i = 1;

    while(ptr->next != NULL)
    {
        if(i == k)
        {
            temp = ptr;
        }
        i++;
        ptr = ptr->next;
    }

    ptr->next = temp;
}

bool detectCycle(node* head)
{
    node *fast = head, *slow = head;
    while(fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;

        if(fast == slow)
        {
            return true;
        }
    }

    return false;
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

    createCycle(head, k);

    cout << detectCycle(head);
    return 0;
}