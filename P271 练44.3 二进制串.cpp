#include <bits/stdc++.h>
using namespace std;

const int N = 4e1 + 5;

int t, n;
char s[N];

inline void input() {
    cin >> t;
}

inline void solve() {
    for (int k = 1; k <= t; k++) {
        cin >> n;
        int p = 0;
        for (; n; n >>= 1) {
            s[++p] = char('0' + (n & 1));
        }
        for (int i = p; i >= 1; i--) {
            cout << s[i];
        }
        cout << "\n";
    }
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    solve();
    return 0;
}
