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
        int var = pushStack.top();
        pushStack.pop();

        if (pushStack.empty())
        {
            return var;
        }
        
        int item = pop();
        pushStack.push(var);
        return item;
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
