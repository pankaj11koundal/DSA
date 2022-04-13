#include<iostream>
#include<stack>

using namespace std;

class Queue
{
private:
    int N;
    stack<int> pushStack;
    stack<int> popStack;
public:

    Queue()
    {
        N = 0;
    }

    void push(int x)
    {
        pushStack.push(x);
        N++;
    }

    int pop()
    {
        if (pushStack.empty() && popStack.empty())
        {
            cout << "Queue is empty";
            return -1;
        }
        
        while (!pushStack.empty())
        {
            popStack.push(pushStack.top());
            pushStack.pop();
        }
        int val = popStack.top();
        popStack.pop();
        return val;
    }

    int size()
    {
        if (pushStack.empty() && popStack.empty())
        {
            return -1;
        }

        return N;
    }
};

int main()
{
    Queue q;

    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    cout << q.pop();
    cout << q.pop();
    cout << q.pop();
    cout << q.pop();
    cout << q.pop();
    cout << q.pop();

}
