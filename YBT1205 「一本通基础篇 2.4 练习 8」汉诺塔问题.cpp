#include <bits/stdc++.h>
using namespace std;

int n;
char a, b, c;

inline void hanoi(int x, char p, char r, char q) {
    if (x > 1) {
        hanoi(x - 1, p, q, r);
    }
    cout << p << "->" << x << "->" << q << "\n";
    if (x > 1) {
        hanoi(x - 1, r, p, q);
    }
}

inline void input() {
    cin >> n >> a >> b >> c;
}

inline void solve() {
    hanoi(n, a, c, b);
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    input();
    solve();
    return 0;
}
