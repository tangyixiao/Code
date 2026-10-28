#include <bits/stdc++.h>
using namespace std;

long long n, x, y;

signed main() {
    cin >> n >> x >> y;
    for (long long i = 1; i * x < n; i++) {
        long long t = n - i * x;
        if (t % y == 0) {
            long long j = t / y;
            if (j >= 1 && i + j > 50) {
                cout << i << " " << j << "\n";
            }
        }
    }
    return 0;
}
