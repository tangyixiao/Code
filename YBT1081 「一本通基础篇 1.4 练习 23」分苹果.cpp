#include <bits/stdc++.h>
using namespace std;

int n;

inline void input() {
    cin >> n;
    return;
}

inline void solve() {
    int s = 0;
    for (int i = 1; i <= n; i++) {
        s += i;
    }
    cout << s << "\n";
    return;
}

signed main() {
    input();
    solve();
    return 0;
}