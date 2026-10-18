#include <bits/stdc++.h>
using namespace std;
const int N = 10 + 5;
int n, f[N], a[N], vis[N];
string s;

inline void input() {
    cin >> n >> s;
    for (int i = 1; i <= n; i++) {
        a[i] = s[i - 1] - '0';
    }
}

inline void solve() {
    f[0] = 1;
    for (int i = 1; i <= n; i++) {
        f[i] = f[i - 1] * i;
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        vis[a[i]] = 1;
        int c = 0;
        for (int j = 1; j < a[i]; j++) {
            c += !vis[j];
        }
        ans += c * f[n - i];
    }
    cout << ans + 1 << "\n";
    return;
}

signed main() {
    input(), solve();
    return 0;
}