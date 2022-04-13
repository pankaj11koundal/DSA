#include<iostream>
#include<stack>

using namespace std;

int evaluation(string eq)
{
    stack<int> st;

    for (int i = 0; i < eq.length(); i++)
    {
        if (eq[i] >= '0' && eq[i] <= '9') 
        {
            st.push(eq[i] - '0');
        }
        else
        {
            int op1 = st.top();
            st.pop();
            int op2 = st.top();
            st.pop();

            switch (eq[i])
            {
            case '+':
                st.push(op2 + op1);
                break;
            
            case '-':
                st.push(op2 - op1);
                break;

            case '/':
                st.push(op2 / op1);
                break;

            case '*':
                st.push(op2 * op1);
                break;

            case '^':
                st.push(op2 ^ op1);
                break;

            default:
                break;
            }
        }
    }
    return st.top();
}

int main()
{
    string eq;
    cout << evaluation("46+2/5*7+");
    return 0;
}