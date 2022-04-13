// Implementing queue as stack where pop operation is more costly 

#include<iostream>
#include<queue>

using namespace std;

class Stack
{
private:
    int n;
    queue<int> q1, q2;

public:

    Stack()
    {
        n = 0;
    }
    void push(int x)
    {
        q1.push(x);

    }
    
    void pop()
    {
        if (q1.empty())
        {
            cout << "Stack is empty";
            // return -1;
        }

        while (!q1.size() != 1)
        {
            q2.push(q1.front());
            q1.pop();
        }

        q1.pop();
        
        queue<int> temp = q1;
        q1 = q2;
        q2 = temp;
        // return val;
    }

    int top()
    {
        if (q1.empty())
        {
            cout << "Stack is empty";
            return -1;
        }

        while(q1.size() != 1)
        {
            q2.push(q1.front());
            q1.pop();
        }

        int topelement = q1.front();

        q2.push(topelement);

        queue<int> temp = q1;
        q1 = q2;
        q2 = temp;
        
        return topelement;
    }
};

int main()
{

    Stack st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);

    st.pop();
    st.pop();
    st.pop();
    st.pop();
    st.pop();
    st.pop();
    return 0;
}