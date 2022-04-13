// Program to implement the priority queue of stl in cpp

#include<iostream>
#include<queue>

using namespace std;

int main()
{
    priority_queue<int> max;
    max.push(1);
    max.push(2);
    max.push(3);
    max.push(4);

    int n = max.size();

    for (int i = 0; i < n; i++)
    {
        cout << max.top() << " ";
        max.pop();
    }
    
    cout << max.empty();

    return 0;
}

