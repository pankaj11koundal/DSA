// Program to show the implementation of the default parameters of templates

#include<iostream>
using namespace std;

template<class t1, class t2=float>
class TwoParameter
{
    t1 *x;
    t2 *y;

public:

    TwoParameter()
    {
        x = new t1;
        y = new t2;
    }

    void setVales(t1 a, t2 b)
    {
        *x = a;
        *y = b;
    }

    void displayValues()
    {
        cout << *x << " " << *y;
    }
};

int main()
{;
    TwoParameter<int> x;
    x.setVales(1, 1.3);
    x.displayValues();
    return 0;
}