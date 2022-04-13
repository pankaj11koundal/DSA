// Program to implement the linked list in stl cpp

#include<iostream>
#include<list>
#include<queue>

using namespace std;

int main()
{
    list<int> l;
    queue<int> q;
    int n = 4;
    cout << "size-> " << l.size();
    cout << endl;

    l.push_back(1);
    l.push_back(2);
    l.push_back(3);
    l.push_back(4);
    
    for(auto i = l.begin(); i != l.end(); i++)
    {
        cout << *i << " ";
    }
    cout << endl;

    cout << l.front() << endl;
    cout << l.back() << endl;
    // list<int>::iterator it = l.begin();
    // list<int>::iterator it1 = l.begin();
    // advance(it1, 2);

    // l.erase(it, it1);
    
    // for(auto i = l.begin(); i != l.end(); i++)
    // {
    //     cout << *i << " ";
    // }
    // cout << endl;

    l.reverse();
    
    for(auto i = l.begin(); i != l.end(); i++)
    {
        cout << *i << " ";
    }
    cout << endl;

    l.clear();
    
    for(auto i = l.begin(); i != l.end(); i++)
    {
        cout << *i << " ";
    }
    cout << endl;

    cout << l.empty() << endl;

    return 0;
}