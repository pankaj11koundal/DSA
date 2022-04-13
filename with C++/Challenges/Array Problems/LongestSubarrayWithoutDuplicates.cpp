#include<bits/stdc++.h>

using namespace std;

int longestSubarrayWithoutDuplicates(string str)
{
    int arr[265] = {-1}, start = -1, maxlen = 0;
    for (int i = 0; i < str.length(); i++)
    {
        if (arr[str[i]] > start)
        {
            start = arr[str[i]];
        }
        arr[str[i]] = i;

        maxlen = max(maxlen, i - start);
    }
    return maxlen;
}

int main()
{
    string str;
    cout << "Enter the string: ";
    cin >> str;

    cout << longestSubarrayWithoutDuplicates(str);

    return 0;
}