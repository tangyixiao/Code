#include <bits/stdc++.h>
using namespace std;

const int N = 1e2 + 5;

char s1[N], s2[N];

inline void input() {
    cin >> s1 >> s2;
}

inline void solve() {
    string a = s1, b = s2;
    bool ok = false;
    for (int i = 0; i < 2; i++) {
        if ((b + b).find(a) != string::npos) {
            ok = true;
        }
        if ((a + a).find(b) != string::npos) {
            ok = true;
        }
    }
    cout << (ok ? "true" : "false") << "\n";
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    solve();
    return 0;
}