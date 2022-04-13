// Program to print the prime numbers upto given number using seive of eratosthenes

#include<iostream>

using namespace std;

int main()
{
    int n, arr[100] = {0};
    cout << "Enter the number upto you want to find prime numbers: ";
    cin >> n;

    // Logic code for seive of eratosthenes
    for (int i = 2; i <= n; i++)
    {
        for (int j = i*i; j <= n; j += i)
        {
            if (arr[j] == 0)
            {
                arr[j] = 1;
            }   
        }  
    }

    cout << "Prime numbers between 1 to " << n <<": ";
    for (int i = 2; i <= n; i++)
    {
        if (arr[i] == 0)
        {
            cout << i << " ";
        }
    }
    
    return 0;
}
