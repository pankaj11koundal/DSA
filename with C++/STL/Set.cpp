#include<iostream>
#include<set>

using namespace std;

int main()
{
    set<int> s;
    s.insert(1);
    s.insert(1);
    s.insert(1);
    s.insert(2);
    s.insert(3);
    s.insert(3);
    s.insert(4);
    s.insert(5);

    for(auto i:s)
    {
        cout << i << " ";
    }
    cout << endl;

    cout << s.size() << endl;

    s.erase(s.begin());
    for(auto i:s)
    {
        cout << i << " ";
    }
    cout << endl;

    cout << s.empty() << endl;

    set<int>:: iterator itr;
    itr = s.find(3);
    
    for (itr; itr != s.end(); itr++)
    {
        cout << *itr << " ";
    }
    
    return 0;
}