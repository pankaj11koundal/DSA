// Cpp program to demonstrate the working of the arrays

#include<array>
#include<iostream>

using namespace std;

int main()
{

    array<int, 5> arr = {1, 2, 3, 4, 5};
    cout << arr.front() << endl;
    cout << arr.back() << endl;
    cout << "Khali hai kya array: " << arr.empty() << endl;
    cout << arr.max_size();

    cout<< endl << "Iterating over array: ";
    for(auto i: arr)
    {
        cout << i;
    }
}