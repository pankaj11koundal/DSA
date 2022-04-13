#include<bits/stdc++.h>

using namespace std;

int largestRectangleInHistogram(int arr[], int n)
{
    int maxArea = 0;
    for (int i = 0; i < n; i++)
    {
        int l = i;
        int r = i;
        int height = arr[i];

        while (l >= 0 && arr[l] >= height)
        {
            l--;
        }
        while (r < n && arr[r] >= height)
        {
            r++;
        }

        l += 1;
        r -= 1;
        int area = (r - l + 1) * height;
        cout << area << " ";
        maxArea = max(maxArea, area);
        cout << endl;
    }
    cout << endl;
    return maxArea;
}

int main()
{
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    int arr[n];

    cout << "Enter the elements in the array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    
    cout << largestRectangleInHistogram(arr, n);
}
