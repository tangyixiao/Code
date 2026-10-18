#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 5;

int n;

inline int f(int x) {
    if (x == 1) {
        return 1;
    }
    return f(x - 1) + x;
}

inline void input() {
    cin >> n;
}

inline void solve() {
    input();
    cout << f(n) << "\n";
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}