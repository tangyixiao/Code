#include <bits/stdc++.h>
using namespace std;

string s;
long long n;

inline void input() {
    cin >> s;
}

inline void solve() {
    n = 0;
    for (int i = 0; i < (int)s.size(); ++i) {
        n = n * 8 + (s[i] - '0');
    }
    cout << n << "\n";
    return;
}

signed main() {
    input();
    solve();
    return 0;
}