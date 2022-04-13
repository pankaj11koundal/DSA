// Cpp program to implement the Queue in stl 

#include<iostream>
#include<queue>

using namespace std;

int main()
{
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    cout << q.size() << endl;

    cout << q.front() << endl;
    int n = q.size();

    for (int i = 0; i < n; i++)
    {
        cout << q.front();
        q.pop();
    }
    cout << endl;
    cout << q.empty() << endl;

    return 0;
}