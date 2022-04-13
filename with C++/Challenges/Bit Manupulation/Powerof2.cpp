// To check whether number is in the power of 2 or not 

#include<iostream>

using namespace std;

int main()
{
    int n;
    cout << "Enter the number: ";
    cin >> n;
    
    if ((n && !(n & n-1)))
    {
        cout << "The number is in the power of 2";
    }
    else
        cout << "The number is not in the power of 2";
    
    return 0;
}
