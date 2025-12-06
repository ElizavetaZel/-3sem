// 3
#include <iostream>
using namespace std;

union fu 
{ 
    float f; 
    unsigned int u; 
};

int main()
{
    cout << fixed;
    cout.precision(2);
    
    fu k;
    float a = 16700000;
    
    while (true)
    {
        k.f = a;
        cout << a << endl;
        a = a + 1;
    }
    
    return 0;
}


