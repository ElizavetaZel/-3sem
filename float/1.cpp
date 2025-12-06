// 1
#include <iostream>
using namespace std;

union fu {
    float f;
    unsigned int u;
};

void binary(unsigned int n) {
    for (int i = 8 * sizeof(n) - 1; i >= 0; i--) {
        unsigned int mask = 1 << i;
        if (n & mask)
            cout << "1";
        else
            cout << "0";
    }
}

int main() {
    fu a;
    cin >> a.f;
    binary(a.u);
    return 0;
}
