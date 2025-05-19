#include <iostream>

using namespace std;

// Class

class Calculator
{
    public:
    int add(int a, int b);  
};

inline int Calculator::add(int a, int b) { return a + b; }

int main()
{
    Calculator cal;
    cout << cal.add(3, 4) << endl;

    return 0;
}
