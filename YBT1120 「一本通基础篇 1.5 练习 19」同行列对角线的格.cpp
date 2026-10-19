#include <bits/stdc++.h>
using namespace std;

int n, i0, b, c;

inline void input() {
    cin >> n >> i0 >> b;
    return;
}

inline void out(int x, int y) {
    if (c++) {
        cout << " ";
    }
    cout << "(" << x << "," << y << ")";
    return;
}

inline void solve() {
    for (int j = 1; j <= n; j++) {
        out(i0, j);
    }
    cout << "\n", c = 0;
    for (int i = 1; i <= n; i++) {
        out(i, b);
    }
    cout << "\n", c = 0;
    for (int i = max(1, i0 - b + 1); i <= min(n, n + i0 - b); i++) {
        out(i, i + b - i0);
    }
    cout << "\n", c = 0;
    for (int i = min(n, i0 + b - 1); i >= max(1, i0 + b - n); i--) {
        out(i, i0 + b - i);
    }
    cout << "\n";
    return;
}

signed main() {
    input();
    solve();
    return 0;
}