#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int algramsInString(int arr1[], string str, int n, string ptr, int k)
{
    int j = 0, i = 0, count = 0;
    int arr2[200] = {0};

    while (j <= n)
    {
        bool f = false;
        if((j - i + 1) < k)
        {
            arr2[str[j]]++;
            j++;
        }
        if((j - i + 1) == k)
        {
            arr2[str[j]]++;

            for (int l = 0; l < k; l++)
            {
                if(arr1[ptr[l]] == arr2[ptr[l]])
                    f = true;
                else
                {
                    f = false;
                    break;
                }
            }

            if (f)
            {
                count++;
            }
            arr2[str[i]]--;
            i++;
            j++;
        }
    }
    
    return count;
}

int main()
{
    string str;
    cout << "Enter the string: ";
    cin >> str;

    string ptr;
    cout << "Enter the pattern: ";
    cin >> ptr;

    int arr1[200] = {0};

    for (int i = 0; i < ptr.length(); i++)
    {
        arr1[ptr[i]]++;
    }
    
    cout << algramsInString(arr1, str, str.length(), ptr, ptr.length());

    return 0;
}