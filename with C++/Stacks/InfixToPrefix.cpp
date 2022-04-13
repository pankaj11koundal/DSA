#include<iostream>
#include<stack>
#include<algorithm>

using namespace std;

int precedance(char ch)
{
    if (ch == '^')
    {
        return 3;
    }
    else if (ch == '*' || ch == '/')
    {
        return 2;
    }
    else if(ch == '+' || ch == '-')
    {
        return 1;
    }
    else
        return 0;
}

string infixToPrefix(string str)
{
    stack<char> st;
    string postfix = "";

    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == ')')
        {
            st.push(str[i]);
        }
        else if ((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z'))
        {
            postfix += str[i];
        }
        else if (str[i] == '(')
        {
            while (!st.empty() && st.top() != ')')
            {
                postfix += st.top();
                st.pop();
            }
            if (!st.empty())
            {
                st.pop();
            }
        }
        else
        {
            while (!st.empty() && precedance(st.top()) > precedance(str[i]))
            {
                postfix += st.top();
                st.pop();
            }
            st.push(str[i]);
        }
    }

    while (!st.empty())
    {
        postfix += st.top();
        st.pop();
    }
    return postfix;
}

int main()
{
    string str;
    cout << "Enter the string: ";
    cin >> str;
    reverse(str.begin(), str.end());
    str = infixToPrefix(str);
    reverse(str.begin(), str.end());
    cout << str;
    return 0;
}