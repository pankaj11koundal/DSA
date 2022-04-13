// Program to show the implementation of the vectors in cpp

#include<bits/stdc++.h>
#include<iostream>

using namespace std;

void display(vector<int> &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
}


int main()
{
    vector<int> v;
    v.reserve(5);
    
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);

    // vector<int> v2 = {6, 7, 8, 9, 10};
    // v.resize(3);
    // v.pop_back();
    display(v);
    cout << endl;

    display(v);
    
    // v.clear();
    // v.erase(v.begin());
    // v.insert(v.end(), 6);
    // display(v);
    // cout << v.empty();
    // display(v2);
    // cout << endl;
    // v.swap(v2);
    // // cout << v.front(); 
    // display(v);
    // cout << endl;
    // display(v2);
    // cout << v.back();
    // v.at[2];

    return 0;
}