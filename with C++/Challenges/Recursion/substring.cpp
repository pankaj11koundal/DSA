// Program to print substring from a string using recursion

#include<iostream>

using namespace std;

void substring(string s, string ans)
{
    if(s.length() == 0)
    {
        cout << ans << endl;
        return;
    }

    char ch = s[0];
    
    substring(s.substr(1), ans);
    substring(s.substr(1), ans + ch);
}

int main()
{
    substring("ABC", "");
}