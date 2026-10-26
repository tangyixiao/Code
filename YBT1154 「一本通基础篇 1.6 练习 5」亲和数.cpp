#include <bits/stdc++.h>
using namespace std;
int sd(int x) {
    int s = 0, i;
    for (i = 1; i * i <= x; i++) {
        if (x % i == 0) {
            if (i < x) {
                s += i;
            }
            if (i != x / i && x / i < x) {
                s += x / i;
            }
        }
    }
    return s;
}
signed main() {
    int a, b;
    for (a = 2;; a++) {
        b = sd(a);
        if (b > a && sd(b) == a) {
            cout << a << " " << b << "\n";
            break;
        }
    }
    return 0;
}
