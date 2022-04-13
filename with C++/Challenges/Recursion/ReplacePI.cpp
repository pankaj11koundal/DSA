// Program to print the '3.14' in place of'pi' in a string using recursion

#include<iostream>

using namespace std;

void replacePi(string s)
{
    if (s.length() == 0)
    {
        return;
    }
    
    if (s[0] == 'p' && s[1] == 'i')
    {
        cout << "3.14";
        replacePi(s.substr(2));
    }
    else
    {
        cout << s[0];
        replacePi(s.substr(1));
    }
}

int main()
{
    
    replacePi("pipiipippppiiippi");
    return 0;
}