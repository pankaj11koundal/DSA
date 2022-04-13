#include<iostream>
#include<map>

using namespace std;

int main()
{
    string ele;
    map<int, string> m;
    int n;
    cout << "Enter the size of the map: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "Insert at " << i << " ";
        cin >> ele;
        m[i] = ele;
    }
    for(auto i: m)
    {
        cout << i.first << ": " << i.second << endl;
    }

    m.insert({5, "five"});

    for(auto i: m)
    {
        cout << i.first << ": " << i.second << endl;
    }

    if (m.count(5))
    {
        cout << "5 is present" << endl;
    }
    
    
    m.erase(3);
    for(auto i: m)
    {
        cout << i.first << ": " << i.second << endl;
    }

    

    return 0;
}