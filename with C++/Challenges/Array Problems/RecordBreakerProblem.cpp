/* Isyana is given the number of visitors at her local theme park on N consecutive days. The number of visitors on    
   the i-th day is V(i). A day is record breaking if it satisfies both of the following conditions:  
      1) The number of visitors on the day is strictly larger than the number of visitors on each of the previous days.
      2) Either it is the last day, or the number of visitors on the day is strictly larger than the number of visitors on the following day.
   
   Note that the very first day cold be a record breaking day!

   Please help Isyana find out the number of record breaking days.
*/

#include<iostream>

using namespace std;

int main()
{
    int n, visitors[100], max, day;

    cout << "Enter the number of days: ";
    cin >> n;

    cout << "Enter the number of visitors on each day: \n";
    for(int i = 0; i < n; i++)
    {
        cin >> visitors[i];
    }

    max = visitors[0];
    day = 1;
    for (int i = 1; i < n; i++)
    {
        if (visitors[i] > max && visitors[i] > visitors[i + 1])
        {
            max = visitors[i];
            day = i + 1;
        cout << "The record breaking day is " << day << ". The number of visitors on that day is " << visitors[day - 1];
        }
    }
    
}