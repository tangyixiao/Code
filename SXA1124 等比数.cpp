#include <bits/stdc++.h>
using namespace std;

int c[10];

inline int cnt(int x) {
    for (; x; x /= 10) {
        if (x % 10 == 0 || c[x % 10]) {
            return 0;
        }
        c[x % 10] = 1;
    }
    return 1;
}

signed main() {
    for (int a = 100; a <= 333; a++) {
        for (int i = 0; i < 10; i++) {
            c[i] = 0;
        }
        if (cnt(a) && cnt(2 * a) && cnt(3 * a)) {
            cout << a << " " << 2 * a << " " << 3 * a << "\n";
        }
    }
    return 0;
}
