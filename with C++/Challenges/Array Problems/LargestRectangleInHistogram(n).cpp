// Program to find the largest rectangle in the histogram with O(n) time complexity

#include <bits/stdc++.h>

using namespace std;

int largestRectangleInHistogram(int hist[], int n)
{
    stack<int> st;
    int i;
    int maxArea = 0;
    int tp;
    int maxAreaTp;

    while (i < n)
    {
        if (st.empty() || hist[i] > hist[st.top()])
        {
            st.push(i++);
        }
        else
        {
            tp = st.top();
            st.pop();

            maxAreaTp = hist[tp] * (st.empty() ? i : i - st.top() - 1);
            maxArea = max(maxArea, maxAreaTp);
        }
    }

    while (!st.empty())
    {
        tp = st.top();
        st.pop();

        maxAreaTp = hist[tp] * (st.empty() ? i : i - st.top() - 1);
        maxArea = max(maxArea, maxAreaTp);
    }
    return maxArea;
}

int main()
{
    int n;
    cout << "Enter the size of the histogram: ";
    cin >> n;

    int hist[n];
    cout << "Enter the bars in the histogram: ";
    for (int i = 0; i < n; i++)
    {
        cin >> n;
    }

    cout << largestRectangleInHistogram(hist, n);
}