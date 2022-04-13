#include <iostream>
#include <stack>

using namespace std;

bool balanceParenthesis(string str)
{
    bool f = true;
    stack<char> st;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '(' || str[i] == '[' || str[i] == '{')
        {
            st.push(str[i]);
        }
        if (str[i] == ')')
        {
            if (st.top() == '(')
            {
                st.pop();
            }
            else
            {
                return false;
            }
        }
        else if (str[i] == '}')
        {
            if (st.top() == '{')
            {
                st.pop();
            }
            else
            {
                return false;
            }
        }
        else if (str[i] == ']')
        {
            if (st.top() == '[')
            {
                st.pop();
            }
            else
            {
                return false;
            }
        }
    }

    if (!st.empty())
    {
        return false;
    }

    return true;
}

int main()
{
    string str;
    cout << "Enter the string: ";
    cin >> str;
    cout << balanceParenthesis(str);
    return 0;
}