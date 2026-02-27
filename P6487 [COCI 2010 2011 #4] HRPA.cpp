#include <bits/stdc++.h>
using namespace std;
long long n, x, y, z;
int main() {
    cin >> n;
    for (;;) {
        if (n == 1 || n == 2) {
            cout << n;
            exit(0);
        }
        x = 1, y = 2, z = 3;
        for (; z < n;) {
            x = y, y = z, z = x + y;
        }
        if (z == n) {
            cout << n;
            exit(0);
        } else {
            n -= y;
        }
    }
    return 0;
}
