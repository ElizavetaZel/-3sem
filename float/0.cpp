// 0
#include <iostream>
using namespace std;

int main() {
    unsigned int x;
    cin >> x;
    int total_bits = sizeof(x) * 8;

    // cдвиги
    for (int i = total_bits - 1; i >= 0; i--) {
        unsigned int temp = x;
        temp = temp >> i;
        temp = temp & 1;
        cout << temp;
    }
    cout << endl;

    // маски
    for (int i = total_bits - 1; i >= 0; i--) {
        unsigned int mask = 1;
        mask = mask << i;

        if ((x & mask) != 0) {
            cout << "1";
        } else {
            cout << "0";
        }
    }
    cout << endl;

    return 0;
}
