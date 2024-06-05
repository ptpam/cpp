#include <iostream>
using namespace std;

class GFG
{
public:
    static int a; // static variable
    int b;        // instance variable
public:
    void funct()
    {
        int c; // local variable
    };
};

int main()
{

    int a;  // declaration of variable a
    a = 10; // initialization of a

    int b = 20; // declaration + initialization

    char a123 = 'a'; // declaration + definition of variable a123

    float c; // declaration + definition of c as the memory is allocated and some garbage value is assigned

    int _c, _d45, e; // multiple declaration and definitions

    cout << a123 << endl;

    return 0;
}