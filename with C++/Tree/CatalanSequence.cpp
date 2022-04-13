#include<iostream>

using namespace std;

int catalanSequence(int n)
{

    if (n == 0 || n == 1)
    {
        return 1;
    }
    
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        res += catalanSequence(i) * catalanSequence(n - i - 1);
    }
    
    return res;
}

int main()
{
    int n;
    cout << "Enter the number of numbers of terms upto where you want catalan sequence: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cout << catalanSequence(i) << " ";
    }

    return 0;    
}
