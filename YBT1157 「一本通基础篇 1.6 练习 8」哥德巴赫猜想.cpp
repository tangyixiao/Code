#include <bits/stdc++.h>
using namespace std;
const int N = 1e2 + 5;
int i, j, n;
bool f[N];
signed main() {
    for (i = 2; i <= 100; i++) {
        f[i] = true;
    }
    for (i = 2; i * i <= 100; i++) {
        if (f[i]) {
            for (j = i * i; j <= 100; j += i) {
                f[j] = false;
            }
        }
    }
    for (n = 6; n <= 100; n += 2) {
        for (i = 3; i <= n / 2; i++) {
            if (f[i] && f[n - i]) {
                cout << n << "=" << i << "+" << n - i << "\n";
                break;
            }
        }
    }
    return 0;
}
