// Program to print substring of a string with their ASCII codes using recursion

#include<iostream>

using namespace std;

void substring(string s, string ans)
{
    if (s.length() == 0)
    {
        cout << ans << endl;
        return;
    }
    
    char ch = s[0];
    int code = ch;

    substring(s.substr(1), ans);
    substring(s.substr(1), ans + ch);
    substring(s.substr(1), ans + ch + to_string(code));
}

int main()
{
    substring("AB", "");
}