#include <bits/stdc++.h>
using namespace std;

string s;
int n;

inline void input() {
    cin >> n >> s;
    return;
}

inline void solve() {
    long long ans = 0;
    for (int i = 0; i < (int)s.size(); i++) {
        ans = ans * 2 + s[i] - '0';
    }
    cout << ans << "\n";
    return;
}

signed main() {
    input();
    solve();
    return 0;
}
