#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int n;
long long b, s;

inline void input() {
    cin >> n >> b;
}

inline void solve() {
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x, s += x;
        if (s >= b) {
            cout << i << "\n";
            return;
        }
    }
    cout << "-1\n";
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    solve();
    return 0;
}
