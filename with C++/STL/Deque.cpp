// Program to implement the Deque in C programming

#include<iostream>
#include<deque>

using namespace std;

int main()
{
    deque<int> d;
    d.push_back(1);
    d.push_front(2);
    d.push_back(3);
    d.push_front(4);

    cout << d.size() << endl;
    cout << d.max_size() << endl;
    // d.shrink_to_fit();
    // cout << d.size() << endl;
    cout << d.front() << endl;
    cout << d.back() << endl;
    d.insert( d.begin() + 2, 5);

    for (int i = 0; i < d.size(); i++)
    {
        cout << d[i] << " ";
    }

    cout << endl;

    d.erase(d.begin()+ 2);

    for (int i = 0; i < d.size(); i++)
    {
        cout << d[i] << " ";
    }
    cout << endl;

    d.clear();
    for (int i = 0; i < d.size(); i++)
    {
        cout << " ";
    }
    cout << endl;

    return 0;
}
