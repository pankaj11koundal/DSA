// Program to perform the vector multiplicatin using the templates

#include <iostream>

using namespace std;

template <class t>
class Vector
{
    int size;
    t *arr;

public:
    Vector(int size)
    {
        this->size = size;
        this->arr = new t[size];
    }

    void setValues()
    {
        for (int i = 0; i < size; i++)
        {
            cin >> arr[i];
        }
    }

    t dotProduct(Vector &v)
    {
        t d = 0;

        for (int i = 0; i < this->size; i++)
        {
            d = d + this->arr[i] * v.arr[i];
        }
        
        return d;
    }
};

int main()
{
    Vector<float> v1(3), v2(3);
    cout << "Enter the magnitude of the first vector: ";
    v1.setValues();
    
    cout << "Enter the magnitude of the second vector: ";
    v2.setValues();

    cout << "Dot product of two vectors are: " << v1.dotProduct(v2);

    return 0;
}