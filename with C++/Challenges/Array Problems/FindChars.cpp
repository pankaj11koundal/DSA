#include<iostream>

using namespace std;

int main()
{
    string str;
    cout << "Enter the string: ";
    cin >> str;

    char ch = str[str.length() - 1];
    int i;
    for(i = str.length() - 2; i >= 0; i--)
    {
        if (str[i] == ch)
        {
            cout << "Minimum characters to be inserted to make our given string palindrome is " << i;
            break;
        }
    }

    if (i < 0)
    {
        cout << "Minimum characters to be inserted to make our given string palindrome is " << str.length() - 1;
    }
    return 0;
}
