// Pratice program of substring with k unique properties.

#include<iostream>
#include<map>
#include<bits/stdc++.h>

using namespace std;

int kUniqueCharacters(string str, int k){
    int i = 0, j = 0, larlen = INT_MIN;
    map<char, int> m;

    while (j < str.length())
    {
        m[str[j]]++;
        if (m.size() < k)
        {
            j++;
        }
        else if (m.size() == k)
        {larlen = max(larlen, j - i + 1);
            j++;
        }
        else if (m.size() > k)
        {
            while (m.size() > k)
            {
                m[str[i]]--;
                if(m[str[i]] == 0){
                    m.erase(str[i]);
                }
                i++;
            }
        }
    }
    return larlen;
}


int main()
{
    string str = "aabadcbebebe";
    int k = 3;

    cout << kUniqueCharacters(str, k);
    return 0;
}