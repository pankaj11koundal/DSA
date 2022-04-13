// C++ program to show the implementation of the infix to postfix conversion

#include<iostream>
#include<conio.h>
#include<string.h>

using namespace std;

class Stack
{
private:
    int top;
    int size;
    char *ch;

    public:
    Stack(int n)
    {
        size = n;
        top = -1;
        ch = new char[size];
    }

    void push(char Char)
    {
        top ++;
        ch[top] = Char;
    }

    char pop()
    {
        char Char = ch[top];
        char *ptr = &ch[top];
        delete ptr;
        top--; 
        return Char; 
    }

    char ReturnChar()
    {
        return ch[top];
    }
    
    void Display()
    {
        int i = 0;
        while (i != top +1)
        {
            cout << "the value at " << i << " is " << ch[i] << endl;
            i++;
        }
    }

    int ReturnTop()
    {
        return top;
    }
};

int precedance(char Ch)
{
    if (Ch == '*' || Ch == '/')
        return 3;
    else if (Ch == '+' || Ch == '-')
    {
        return 2;
    }
    else
    {
        return 1;
    }
}

void ToPostfix(char *in, char *po, Stack *st)
{
    int i=0, j=0;
    while (in[i] != '\0')
    {
        if (isalnum(in[i])) 
        {
            po[j] = in[i];
            i++;
            j++;
        }
        else
        {
            if (st->ReturnTop() == -1)
            {
                st->push(in[i]);
            }
            else if (precedance(in[i] > precedance(st->ReturnChar())))
            {
                st->push(in[i]);
            }
            else
            {
                while(precedance(in[i]) < precedance(st->ReturnTop()))
                {
                    char ch = st->pop();
                    po[j] = ch;
                }
                st->push(in[i]);
            }
            i++;
            j++;
        }       
    }

    while (st->ReturnTop() != -1)
    {
        po[j] = st->pop();
        j++;
    }
}

int main()
{
    char Infix[50];
    char Postfix[50];

    cout << "Enter the infix expression: ";
    gets(Infix);
    // cout << "Infix expression is " << Infix;

    Stack st(strlen(Infix));

    ToPostfix(Infix, Postfix, &st);

    cout << "The Postfix expression is as follow: " << Postfix;

    return 0;
}




