#include <bits/stdc++.h>
using namespace std;

const int N = 1e2 + 5;

char s[N];

inline void input() {
    cin >> s;
}

inline void solve() {
    int n = strlen(s);
    bool ok = true;
    for (int i = 0; i < n / 2; i++) {
        if (s[i] != s[n - 1 - i]) {
            ok = false;
        }
    }
    cout << (ok ? "yes" : "no") << "\n";
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    solve();
    return 0;
}