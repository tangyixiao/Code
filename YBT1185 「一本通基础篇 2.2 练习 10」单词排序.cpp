#include <bits/stdc++.h>
using namespace std;

const int N = 1e2 + 5;

char s[N];
set<string> t;
string w;

inline void input() {
    while (cin >> w) {
        t.insert(w);
    }
}

inline void solve() {
    for (auto &x : t) {
        cout << x << "\n";
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
