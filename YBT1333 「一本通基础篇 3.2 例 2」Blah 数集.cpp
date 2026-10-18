#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 1e6 + 5;
int a, n, s[N];

inline void input() {
    return;
}

inline void solve() {
    while (cin >> a >> n) {
        s[1] = a;
        int p = 1, q = 1;
        for (int i = 2; i <= n; i++) {
            long long x = s[p] * 2 + 1, y = s[q] * 3 + 1;
            s[i] = min(x, y);
            if (s[i] == x) {
                p++;
            }
            if (s[i] == y) {
                q++;
            }
        }
        cout << s[n] << "\n";
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