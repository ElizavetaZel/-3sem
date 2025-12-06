// 2
#include <iostream>
using namespace std;

void binary(unsigned int n) {
    for (int i = 8 * sizeof(n) - 1; i >= 0; i--) {
        unsigned int mask = 1u << i;
        if (n & mask)
            cout << "1";
        else
            cout << "0";
    }
}

int main() {
    cout << fixed;
    cout.precision(2);

    union {
        float f;
        unsigned int u;
    } num;

    float v = 10;

    while (v < 10000000000000000) {
        num.f = v;
        cout << num.f << " ";
        binary(num.u);
        cout << endl;
        v *= 10;
    }
    return 0;
}