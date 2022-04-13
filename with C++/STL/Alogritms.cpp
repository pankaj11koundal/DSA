// Program to implement the alogrithms of standard template liberary

#include<algorithm>
#include<vector>
#include<iostream>

using namespace std;

int main()
{
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    v.push_back(6);
    v.push_back(7);

    cout << binary_search(v.begin(), v.end(), 9) << endl;
    reverse(v.begin(), v.end());

    for(auto i: v)
    {
        cout << i << " ";
    }
    cout << endl;

    // rotating the array
    vector<int> :: iterator itr = v.begin() + 2;
    rotate(v.begin(), itr, v.end());
    for(auto i: v)
    {
        cout << i << " ";
    }
    cout << endl;

    cout << "Upper bound: " << upper_bound(v.begin(), v.end(), 4) - v.begin() <<endl;
    cout << "lower bound: " << lower_bound(v.begin(), v.end(), 4) - v.begin() <<endl;
    return 0;
}