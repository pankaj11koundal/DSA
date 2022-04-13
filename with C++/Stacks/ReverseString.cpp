// C++ Program to implement the reversing of string using stack 
//         ex: "Hy, how are you doing?";
//             "doing? you are how Hy,"

#include<iostream>
#include<stack>

using namespace std;

void reverseString(string str)
{
    stack<string> st;

    for (int i = 0; i < str.length(); i++)
    {
        string word ="";
        while (str[i] != ' ' && i < str.length())
        {
            word += str[i];
            i++;
        }
        st.push(word);
    }
    
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
}

int main()
{
    reverseString("Hyy, how are you doing?");
    return 0;
}