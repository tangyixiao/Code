#include <bits/stdc++.h>
using namespace std;

const int N = 85;
long long f[N];

inline void input() {
    f[1] = 1, f[2] = 2, f[3] = 3;
    for (int i = 4; i < N; i++) {
        f[i] = f[i - 1] + f[i - 3];
    }
    return;
}

inline void solve() {
    int n;
    cin >> n;
    cout << f[n] << "\n";
    return;
}

signed main() {
    input();
    solve();
    return 0;
}
