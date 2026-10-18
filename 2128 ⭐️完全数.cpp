#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 5;
int n;
int p[N];

inline void input() {
    cin >> n;
}

inline void solve() {
    for (int i = 2; i <= n; ++i) {
        p[i] = 1;
        for (int j = 2; j * j <= i; ++j) {
            if (i % j) {
                continue;
            }
            p[i] += j;
            if (i / j != j) {
                p[i] += i / j;
            }
        }
    }
    for (int i = 2; i <= n; ++i) {
        if (p[i] == i) {
            cout << i << "\n";
        }
    }
    return;
}

signed main() {
    input();
    solve();
    return 0;
}
