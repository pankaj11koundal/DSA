#include<iostream>

using namespace std;

int main()
{
    int a[8], count, max = 0, val, i, j, start, end;

    for(i = 0; i < 8; i++)
    {
        cin >> a[i];
    }

    for(i = 0; i < 8; i++)
    {
        count = 0;
        val = a[i] - a[i + 1];
        for (j = i; j < 8; j++)
        {
            if(a[j] - a[j + 1] == val)
            {
                count++;
            }
            else
                break;
        }
        
        if(count > max)
        {
            max = count;
            cout << max << "\n";
            start = i;
            end = j;           
        }
    }

    cout << "The longest airthmetic subarray is of size " << max << " and the array is: " ;
    for( ; start <= end; start++)
    {
        cout << a[start] << " ";
    }


    // More effecient code with less time complexity

    val = a[1] = a[0];
    count = val;
    max = 2;
    j = 2;

    while(j < 8)
    {
        
        if(a[j] - a[j+1] == val)
        {
            count ++;
        }
        else
        {
            val = a[j] - a[j+1];
            count = 2;
        }

        if (count > max)
        {
            max = count;
        }
        
        j++;
    }
    cout << "The longest airthmetic subarray is of size " << max ;
}
