#include<iostream>
#include<vector>

using namespace std;

int main()
{
    string str;
    vector<char> v;
    cin >> str;
    for (int i = 0; i < str.length(); i++)
    {
        v[i] = str[i];
    }
    
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i];
    }
    

    return 0;
}