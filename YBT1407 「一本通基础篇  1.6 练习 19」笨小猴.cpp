#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;

char s[N];
int c[N], mx, mn;

inline void input() {
    cin >> s;
}

inline bool ps(int n) {
    if (n < 2) {
        return false;
    }
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

inline void solve() {
    mn = 1e9;
    for (int i = 0; s[i]; ++i) {
        ++c[s[i] - 'a'];
    }
    for (int i = 0; i < 26; ++i) {
        if (c[i]) {
            mx = max(mx, c[i]), mn = min(mn, c[i]);
        }
    }
    if (ps(mx - mn)) {
        cout << "Lucky Word\n"
             << mx - mn << "\n";
    } else {
        cout << "No Answer\n0\n";
    }
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    input();
    solve();
    return 0;
}
