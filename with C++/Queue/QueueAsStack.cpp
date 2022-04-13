// Implementing queue as stack where push operation is more costly 

#include<iostream>
#include<queue>

using namespace std;

class Stack
{
private:
    int n;
    queue<int> q1, q2;

public:
    void push(int x)
    {
        queue<int> temp;
        q2.push(x);
        n++;
        while(!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }

        temp = q1;
        q1 = q2;
        q2 = temp;
    }

    int pop()
    {
        if (q1.empty())
        {
            cout << "Queue is empty";
            return -1;
        }
        
        int val = q1.front();
        q1.pop();
        return val;
    }

    int top()
    {
        return q2.front();
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

    cout << st.pop() << endl;
    cout << st.pop() << endl;
    cout << st.pop() << endl;
    cout << st.pop() << endl;
    cout << st.pop() << endl;
    cout << st.pop() << endl;


    return 0;
}