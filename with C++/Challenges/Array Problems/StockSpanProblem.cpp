#include<bits/stdc++.h>

using namespace std;

void stockSpan(int stockArray[], int n)
{
    stack<int> stockStack, daysStack;
    int days[n];
    int i = 0;

    while (i < n)
    {
        if (stockStack.empty() || stockArray[i] < stockStack.top())
        {
            stockStack.push(stockArray[i]);
            daysStack.push(1);
            days[i] = 1;
        }
        else
        {
            int var = 1;
            while (stockArray[i] > stockStack.top())
            {
                stockStack.pop();
                var += daysStack.top();
                daysStack.pop();
            }
            stockStack.push(stockArray[i]);
            daysStack.push(var);
            days[i] = var;
        }
        i++;
    }
    
    for (int i = 0; i < n; i++)
    {
        cout << stockArray[i] << ": " << days[i] << endl;
    }
}

int main()
{
    int n;
    cout << "Enter the number of stocks: ";
    cin >> n;

    int stockArray[n];
    cout << "Enter the elements in the stock array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> stockArray[i];
    }
    
    stockSpan(stockArray, n);

    return 0;
}