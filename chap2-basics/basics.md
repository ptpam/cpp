### 2.2.2 Types, Variables, and Arithmetic

A `declaration` is a statement that introduces a name into the program. It specifies a type for the named entity:

- `type` : defines set of possible values and a set of operations
- `object` : some memory that holds a value of some type
- `value` : set of bits interpreted according to a type
- `variable` : a named object

```bash
bool // Boolean, possible values are true and false
char // character, for example, 'a', ' z', and '9'
int // integer, for example, 1, 42, and 1066
double // double-precision floating-point number, for example, 3.14 and 299793.0
```

```cpp
double d1 = 2.3;
double d2{2.3}

complex<double> z = 1        // a complex number with double-precision floating-point scalars
complex<double> z2 {d1, d2}
complex<double> z3 = {1,2}   // the = is optional with {}

vector<int> v {1,2,3,4,5,6}  // a vector of ints

int i1 = 7.2        // i1 becomes 7
int i2{7.2}         // error: floating-point to integer conversion
int i3 = {7.2}      // error: floating-point to integer conversion (the = is redundant)

```

Whan defining a variable, you don't actually need to state its type explicitly when it can be deduced from the initializer.

```cpp
auto b = true; // a bool
auto ch = 'x';// a char
auto i = 123;// an int
auto d = 1.2;// a double
auto z = sqrt(y); // z has the type of whatever sqrt(y) returns
```

### 2.2.3 Constants

- `const` : the value is promised not to be changed. Primarily specifies interfaces, so that can be passed to functions without fear of it being modified. The compiler enforces the promise made by **const**
- `constexpr` : rougly it means it will be evaluated at compile time. Primarily used to specify constants, allow placement of data in memory where it is unlikely to be corrupted, and for performance.

```cpp
const int dmv = 17;                     // dmv is a named constant
int var = 17;                           // var is not a constant
constexpr double max1 = 1.4∗square(dmv);// OK if square(17) is a constant expression
constexpr double max2 = 1.4∗square(var);// error: var is not a constant expression
const double max3 = 1.4∗square(var);    // OK, may be evaluated at run time
```

A `constexpr` function can be used for non-constant arguments, but when it is done the result is not a constant expression.

```cpp
constexpr double square(double x) { return x∗x; }
```

### 2.2.4 Tests and Loops

```cpp
bool accept()
{
    cout << "Do you want to proceed (y or n)?\n"; // write question

    char answer = 0;
    cin >> answer;

    if (answer == 'y') return true;
    return false;
}

bool accept2(){
    cout << "Do you want to proceed (y or n)?\n"; // write question

    char answer = 0;
    cin >> answer;
    switch(answer){
        case 'y':
            return true
        case 'n':
            return false
        default:
            cout << "I'll take that for a no!\n."
            return false;
    }
}
```

### 2.2.5 Pointers, Arrays, and Loops

In declarations, `*` means "pointer to".

```cpp
char v[6];      // array of 6 characters, the size of array must be constant expression
char* p;        // pointer ro character
char *p = &v[3] // p points to v's fourth element
char x = *p;    // *p is the object points to
```

In an expression, prefix unary `*` means "contents of", and prefix unary `&` means "address of".

```cpp

int v1[10] = {0,1,2,3,4,5,6,7,8,9};
int v2[10]; // to become a copy of v1
for (auto i=0; i!=10; ++i) // copy elements
    v2[i]=v1[i];

for (auto x : v)    // for each x in v - range-for-statement
    cout << x << '\n';
```

In a declaration, the unary suffix `&` means "reference to".

```cpp
T a[n];     // T[n]: array of n Ts
T∗ p;       // T* : pointer to T
T& r;       // T& : reference to T
T f(A);     // T(A) : function taking an argument of type A returning a result of type T
```

We try to ensure that a pointer always points to an object, so that dereferencing it is valid. If there is no objecg to point or if we need to represent the notion of "no object available", `nullptr` value is given to the pointer.

```cpp
double∗ pd = nullptr;
Link<Record>∗ lst = nullptr; // pointer to a Link to a Record
int x = nullptr; // error: nullptr is a pointer not an integer
```

### 2.3.1 Structures

```cpp

struct Vector {
    int sz;         // number or elements
    double* elem;   // pointer to elements
}

void vector_init(Vector& v, int s){
    v.elem = double[s]; // allocate an array of s doubles
    v.sz = s;
}

double read_and_sum(int s)
// read s integers from cin and return their sum; s is assumed to be positive
{
    Vector v;
    vector_init(v, s);          // allocate s elements for v
    for (int i = 0; i != s; ++i)
        cin >> v.elem[i];       // read into elements

    double sum = 0;
    for (int i = 0; i != s, ++i)
        sum += v.elem[i];       // take sum of the elements
    return sum;
}

void f(Vector v, Vector& rv, Vector *pv)
{
    int i1 = v.sz;      // access through name
    int i2 = rv.sz;     // access through reference
    int i3 = pv->sz;    // access through pointer
}

```

### 2.3.2 Classes

A `class` is defined to have a set of members, which can be data, function, or type members. The interface is defined by the `public` members of a class, and `private` members are accessible only through that interface.

```cpp
class Vector{
public:
    Vector(int s): elem{new double[s]}, sz{s} {} // construct a vector
    double& operator[](int i){return elem[i];}  // element access: subscripting
    int size(){return sz;}
private:
    double* elem;   // pointer to the elements
    int sz;         // the number of elements
}

double read_and_sum(int s){
    Vector v(s);
    for (int i = 0; i!= v.size(), ++i)
        cin >> v[i];

    double sum = 0;
    for (int i=0; i != v.size(), i++)
        sum += v[i];

    return sum;
}
```

### 2.3.3 Enumerations

```cpp
enum class Color { red, blue, green };
enum class Traffic_light { green, yellow, red };
Color col = Color::red;
Traffic_light light = Traffic_light::red;

Traffic_light& operator++(Traffic_light& t) // prefix increment: ++
{
    switch (t) {
    caseTraffic_light::green: returnt=Traffic_light::yellow;
    caseTraffic_light::yellow: returnt=Traffic_light::red;
    caseTraffic_light::red: returnt=Traffic_light::green;
    }
}

Traffic_light next = ++light; // next becomes Traffic_light::green

```
