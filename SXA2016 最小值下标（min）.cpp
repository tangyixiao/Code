#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 5;
int n, a[N];

inline void input() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
}

inline void solve() {
    int p = 1;
    for (int i = 2; i <= n; ++i) {
        if (a[i] < a[p]) {
            p = i;
        }
    }
    cout << p - 1 << "\n";
    return;
}

signed main() {
    input();
    solve();
    return 0;
}