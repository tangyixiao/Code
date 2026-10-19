#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;

int n;
__int128 f[N];

inline void input() {
    cin >> n;
}

inline void solve() {
    f[0] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = i; j <= n; ++j) {
            f[j] += f[j - i];
        }
    }
    string s;
    __int128 x = f[n];
    for (; x; x /= 10) {
        s += char('0' + int(x % 10));
    }
    if (s.empty()) {
        s = "0";
    }
    reverse(s.begin(), s.end());
    cout << s << "\n";
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    input();
    solve();
    return 0;
}
