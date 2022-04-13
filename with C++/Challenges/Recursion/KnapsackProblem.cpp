// There are n number of items, each items has different value and different weight, we have to insert the item in the knapsack such that the capacity of the kanpsach should not be excided by the total weight of the knapsack and we get the maximum value.

#include<iostream>

using namespace std;

int knapsack(int values[], int weight[], int n, int W)
{
    if(n == 0 || W == 0)
    {
        return 0;
    }

    if (W < weight[n - 1])
    {
        return knapsack(values, weight, n, W);
    }
    
    return max(knapsack(values, weight, n - 1, W - weight[n - 1]) + values[n - 1],knapsack(values, weight, n - 1, W));
}

int main()
{
    int values[3] = {100, 50, 150};
    int weight[3] = {30, 40 ,50};
    cout << knapsack(values, weight, 3, 90);
    return 0;
}