#include<iostream>
#include<map>

using namespace std;

int main()
{
    int j;
    map<char, int> m;
    str s = "abcdecabc";

    while(j < s.length())
    {
        m[s[i]] ++;
    }

    for(auto i: m){
        cout << m.first << m.second;
    }

    m.erase(m[s[2]]);

    for(auto i: m){
        cout << m.first << m.second;
    }

    return 0;
}