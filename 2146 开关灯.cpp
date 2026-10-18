#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
int n, a[N];

inline void input() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        a[i] = 0;
    }
}

inline void solve() {
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j += i) {
            a[j] ^= 1;
        }
    }
    bool t = false;
    for (int i = 1; i <= n; i++) {
        if (a[i]) {
            if (t) {
                cout << " ";
            }
            t = true, cout << i;
        }
    }
    cout << "\n";
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    solve();
    return 0;
}
