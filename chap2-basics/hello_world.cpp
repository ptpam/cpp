// instructs compiler to include the declarations of the standard stream I/O facilities
#include <iostream>
using namespace std; // make names from std visible without std::

double square(double x) // square a double precision floating-point number
{
    return x * x;
}

void print_square(double x) // void type means function returns nothing
{
    cout << "the square of x " << x << " is " << square(x) << "\n";
}

int main()
{
    cout << "Hello, World!\n";
    print_square(1.234);
}