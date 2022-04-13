#include<iostream>
#include<vector>

using namespace std;

int main()
{
    string str;
    int i;

    cout << "Enter the string: ";
    cin >> str;
    char ch = str[str.length() - 1];
    for (i = str.length() - 2; i >= 0; i--)
    {
        if (str[i] == ch)
        {
            cout << i;
            break;
        }
    }
    
    if (i < 0)
    {
        cout << str.length() - 1;
    }
    
    return 0;
}