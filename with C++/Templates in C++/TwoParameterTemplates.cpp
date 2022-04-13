// templates with two parameters

#include <iostream>

using namespace std;

template <class t1, class t2>
class TwoParameter
{
    int size;
    t1 *arr1;
    t2 *arr2;

public:

    TwoParameter(int size)
    {
        this->size = size;
        arr1 = new t1[size];;
        arr2 = new t2[size];
    }

    void setValue()
    {
        cout << "Enter the values for 1st array: ";
        for (int i = 0; i < size; i++)
        {
            cin >> arr1[i];
        }
        cout << "Enter the value for 2nd array: ";
        for (int i = 0; i < size; i++)
        {
            cin >> arr2[i];
        }
    }

    t2 returnSum()
    {
        t2 sum = 0;
        for (int i = 0; i < size; i++)
        {
            sum += arr1[i] + arr2[i];
        }
        return sum;
    }
};

int main()
{
    TwoParameter<int, float> t1(3);
    t1.setValue();
    cout << "The sum is " << t1.returnSum();
    return 0;
}