#include<iostream>
#include<stack>

using namespace std;

int evaluation(string eq)
{
    stack<int> st;

    for (int i = eq.length() - 1; i >= 0; i--)
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
                st.push(op1 + op2);
                break;
            
            case '-':
                st.push(op1 - op2);
                break;

            case '/':
                st.push(op1 / op2);
                break;

            case '*':
                st.push(op1 * op2);
                break;

            case '^':
                st.push(op1 ^ op2);
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
    cout << evaluation("-+7*45+20");
    return 0;
}