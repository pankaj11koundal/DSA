#include<iostream>
#include<map>

using namespace std;

int main()
{
    int j;
    map<char, int> m;
    string s = "abcdecabc";

    while(j < s.length())
    {
        m[s[j]] ++;
        cout << m[s[j]] << endl;
    }

    cout << m.size();

    for(auto i: m){
        cout << i.first <<": " << i.second;
    }
    return 0;
}