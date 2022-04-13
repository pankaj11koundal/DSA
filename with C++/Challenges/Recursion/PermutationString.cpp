// Program to print all the possible permutation of a string with help of recursion

#include<iostream>

using namespace std;

void permutation(string s, string ans)
{
    if (s.length() == 0)
    {
        cout << ans << endl;
    }
    
    for (int i = 0; i < s.length(); i++)
    {
        char ch = s[i];
        string ros = s.substr(0, i) + s.substr(i+1, s.length());

        permutation(ros, ans + ch);
    }
}

int main()
{
    permutation("ABC", "");
}
