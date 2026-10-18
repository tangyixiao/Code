#include <bits/stdc++.h>
using namespace std;

const int N = 2e6 + 5;
int d, i0;
bool f[N];

inline void input() { cin >> d >> i0; }

inline void solve() {
    for (int t = 1; t <= i0; ++t) {
        int p = 1;
        for (int s = 1; s < d; ++s) {
            if (f[p]) {
                f[p] = false;
                p = p * 2 + 1;
            } else {
                f[p] = true;
                p *= 2;
            }
        }
        if (t == i0) {
            cout << p << "\n";
        }
    }
    return;
}

signed main() {
    input();
    solve();
    return 0;
}