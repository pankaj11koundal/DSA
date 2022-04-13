// program to print the prime factors of given numbers using SIEVE OF ERATOSTHENES algorithm

#include<iostream>

using namespace std;

void primefactor(int arr[], int n)
{
    for (int i = 2; i <= n; i++)
    {
        arr[i] = i;
    }
    
    for (int i = 2; i <= n; i++)
    {
        if (arr[i] == i)
        {
            for (int j = i*i; j <= n; j += i)
            {
                if (arr[j] == j)
                {
                    arr[j] = i;
                }
            }
            
        }
    }    
    
    cout << "Prime factors of given number " << n << " is ";        
    while (n != 1)
    {
        cout << arr[n] << " ";
        n = n / arr[n];
    }
}

int main()
{
    int n;
    cout << "Enter the number whose prime factors you want to find: ";
    cin >> n;

    int arr[n]; 

    primefactor(arr, n);
    return 0;
}