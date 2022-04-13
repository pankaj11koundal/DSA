// method overloading using templates

#include<iostream>
using namespace std;

template <class t>
class a
{
    t x;

    public:
        a(t n)
        {
            x = n;
        }
        void display()
        {
            cout << x;
        }

        template <class t1>
        void display(t1 y)
        {
            cout << x << " " << y;
        }
};

int main()
{
    a<int> obj(4);
    obj.display();
    cout << endl;
    obj.display(4.3);
    return 0;
}