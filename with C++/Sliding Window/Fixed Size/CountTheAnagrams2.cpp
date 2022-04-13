// Another effecient way of solving the count number of anagrams in the string of a given string 
// This program reduces the space complexity to the size of the given string.

#include <iostream>
#include <map>

using namespace std;

int countTheAnagrams(string ptr, string s)
{
    int ans = 0, i = 0, j = 0, k = ptr.length();

    // map of the character with number of occurence in the pattern string
    map<char, int> m;

    // Creating map with the number of occurence
    for (int i = 0; i < k; i++)
    {
        m[ptr[i]]++;
    }
    
    int count = m.size();
    i = 0;
    while (j < s.length())
    {
        if (m.count(s[j]))
        {
            m[s[j]]--;
            if (m[s[j]] == 0)
            {
                count--;
            }
        }

        if (j - i + 1 < ptr.length())
        {
            j++;
        }
        else
        {
            if (count == 0)
            {
                ans++;
            }
            
            if (m.count(s[i]))
            {
                if (count == 0)
                {
                    count++;
                }
                m[s[i]]++;
            }
            i++;
            j++;
        }
    }
    return ans;
}



int main()
{
    string s = "aabaabaa", ptr = "aaba";
    cout <<  countTheAnagrams(ptr, s);
    return 0;
}