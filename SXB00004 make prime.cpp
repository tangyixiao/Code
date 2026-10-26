#include <bits/stdc++.h>
using namespace std;

const int N = 25, M = 1e4 + 5;
int n, k, cnt, tot;
int a[N], p[M], np;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    for (int i = 2; i <= 10000; i++) {
        int f = 1;
        for (int j = 2; j * j <= i; j++) {
            if (i % j == 0) {
                f = 0;
                break;
            }
        }
        if (f) {
            p[np++] = i;
        }
    }
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int s = 0; s < (1 << n); s++) {
        if (__builtin_popcount(s) != k) {
            continue;
        }
        long long v = 0;
        for (int i = 0; i < n; i++) {
            if (s >> i & 1) {
                v += a[i];
            }
        }
        int f = 1;
        if (v < 2) {
            f = 0;
        }
        for (int j = 0; j < np && 1LL * p[j] * p[j] <= v; j++) {
            if (v % p[j] == 0) {
                f = 0;
                break;
            }
        }
        if (f) {
            tot++;
        }
    }
    cout << tot << "\n";
    return 0;
}
