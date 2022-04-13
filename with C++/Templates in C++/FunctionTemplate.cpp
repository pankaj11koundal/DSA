// Function using the template

#include<iostream>
using namespace std;

template<class t1, class t2>
t2 average(t1 a, t2 b)
{
    return (a + b) / 2;
}

int main()
{

cout << average(1, 2.2);
return 0;
}