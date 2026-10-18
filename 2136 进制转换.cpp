#include <bits/stdc++.h>
using namespace std;

int n, m;
string s;

inline void input() {
    cin >> n;
    cin >> s;
    cin >> m;
}

inline void solve() {
    long long v = 0;
    for (int i = 0; i < (int)s.size(); ++i) {
        int d = s[i] <= '9' ? s[i] - '0' : s[i] - 'A' + 10;
        v = v * n + d;
    }
    string r;
    if (v == 0) {
        r = "0";
    }
    while (v) {
        int d = v % m;
        r = char(d < 10 ? '0' + d : 'A' + d - 10) + r;
        v /= m;
    }
    cout << r << "\n";
    return;
}

signed main() {
    input();
    solve();
    return 0;
}