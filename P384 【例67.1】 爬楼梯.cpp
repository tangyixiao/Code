#include <bits/stdc++.h>
using namespace std;

const int N = 35;
long long f[N];

inline void input() {
    f[1] = 1, f[2] = 2;
    for (int i = 3; i < N; i++) {
        f[i] = f[i - 1] + f[i - 2];
    }
    return;
}

inline void solve() {
    int n;
    while (cin >> n) {
        cout << f[n] << "\n";
    }
    return;
}

signed main() {
    input();
    solve();
    return 0;
}
