#include <bits/stdc++.h>
using namespace std;

int n;
string s;
long long v;

inline void input() {
    cin >> n;
    cin >> s;
}

inline void solve() {
    v = 0;
    for (int i = 0; i < n; ++i) {
        v = v * 2 + (s[i] - '0');
    }
    cout << v << "\n";
    return;
}

signed main() {
    input();
    solve();
    return 0;
}