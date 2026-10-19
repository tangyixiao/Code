#include <bits/stdc++.h>
using namespace std;

int n;

inline void input() {
    cin >> n;
}

inline void solve() {
    long long f = 1, s = 0;
    for (int i = 1; i <= n; ++i) {
        f *= i;
        s += f;
    }
    cout << s << "\n";
    return;
}

signed main() {
    input();
    solve();
    return 0;
}