// Print the given string using recursion only

#include<iostream>

using namespace std;

void ReverseString(string s)
{
    if (s.length() == 0)
    {
        return;
    }

    ReverseString(s.substr(1));
    cout << s[0];
}

int main()
{
    string s;

    cout << "Enter the string: ";
    cin >> s;

    cout << "String before reversing: " << s << endl;
    cout << "String after reversing: ";
    ReverseString(s);
}