#include <bits/stdc++.h>
using namespace std;

int n, d;

inline void input() {
    cin >> n;
    return;
}

inline void solve() {
    for (; n; n /= 10) {
        d = n % 10;
        cout << d << " ";
    }
    cout << "\n";
    return;
}

signed main() {
    input();
    solve();
    return 0;
}