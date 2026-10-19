#include <bits/stdc++.h>
using namespace std;

int a, b, c;

inline void input() {
    cin >> a >> b;
    if (a > b) {
        swap(a, b);
    }
    cin >> c;
    if (c > b) {
        swap(b, c);
    }
    if (c > a) {
        swap(a, c);
    }
}

inline void solve() {
    cout << ((a + b > c) ? "yes" : "no") << "\n";
    return;
}

signed main() {
    input();
    solve();
    return 0;
}
