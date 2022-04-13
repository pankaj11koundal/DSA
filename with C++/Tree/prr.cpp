#include<iostream>
#include<string>
#include<conio.h>

using namespace std;

struct student
{
    int roll;
    string name;
    string Dob;
    float fee;
};

int main()
{
    student s[2];
    
    for (int i = 0; i < 2; i++)
    {
        cout << "Enter the roll no.: endl";
        cin >> s[i].roll;
        cout << "Enter the name: enl";
        getline(cin, s[i].name);
        cout << "Enter the date of birth: ";
        cin >> s[i].Dob;
        cout << "Enter the fees of the student: ";
        cin >> s[i].fee;
    }

    for (int i = 0; i < 2; i++)
    {
        cout << "the roll no.:"
             << s[i].roll;
        cout << "the name:"
            <<s[i].name;
        cout << "the date of birth: "
             << s[i].Dob;
        cout << "the fees of the student: "
             << s[i].fee;
    }
}