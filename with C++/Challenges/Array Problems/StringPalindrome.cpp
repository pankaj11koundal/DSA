#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int findPosition(string str, char key)
{
    for (int i = str.length() - 2; i >= 0; i--)
    {
        if (str[i] == key)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    string str;
    int i;
    vector<char> v;
    cout << "Enter the string: ";
    cin >> str;
    for ( i = 0; i < str.length() - 1; i++)
    {
        v.push_back(str[i]);
    }

    int var = findPosition(str, str[i]);
    
    if (var == -1)
    {
        cout << "The number of character required to add to make the given string palindrome is " << i;
    }
    else
    {
        cout << "The number of character required to make the given string palindrome is " << var;
    }
    return 0;
}