// Program to remove all the x at the back of the string using recursion

#include<iostream>

using namespace std;

string moveX(string s)
{
    if (s.length() == 1)
    {
        return s;
    }

    char ch = s[0];
    string ans = moveX(s.substr(1));

    if (ch == 'x')
    {
        return ans + ch;
    }
    else
        return ch + ans;    
}

int main()
{
    cout << moveX("abxcdxexfxx");
    return 0;
}