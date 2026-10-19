#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;

int n;

inline void input() {
    cin >> n;
}

inline void solve() {
    long long a = 0, b = 1;
    for (int i = 1; i < n; i++) {
        long long t = a + b;
        a = b, b = t;
    }
    cout << a << "\n";
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    solve();
    return 0;
}
