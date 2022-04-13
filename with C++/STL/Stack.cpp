// Program to implement the stack stl in cpp

#include<iostream>
#include<stack>

using namespace std;

int main()
{
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);

    cout << st.size() << endl;
    cout << st.empty() << endl;
    cout << st.top() << endl;
    int n = st.size();
    for (int i = 0; i < n; i++)
    {
        cout << st.top() << endl;
        st.pop();
    }
    
    return 0;
}