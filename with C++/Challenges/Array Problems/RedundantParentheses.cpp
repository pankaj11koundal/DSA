#include<bits/stdc++.h>

using namespace std;

int redundantParenthesis(string str)
{
    stack<char> st;

    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '(' || str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/' || str[i] == '^')
        {
            st.push(str[i]);
        }
        else if (str[i] == ')' && st.top() == '(')
        {
            return 0;
        }
        else
        {
            st.pop();
        }
    }
    return true;
}

int main()
{
    string st;
    cout << "Enter the string: ";
    cin >> st;

    cout << redundantParenthesis(st);
    return 0;
}