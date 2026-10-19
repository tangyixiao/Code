#include <bits/stdc++.h>
using namespace std;

const int N = 1e2 + 5;

int n, m, x[N], y[N], z[N * 2];
int len1, len2;

inline void input() {
    string s, t;
    cin >> s >> t;
    len1 = len2 = 0;
    for (int i = (int)s.size() - 1; i >= 0; i--) {
        x[++len1] = s[i] - '0';
    }
    for (int i = (int)t.size() - 1; i >= 0; i--) {
        y[++len2] = t[i] - '0';
    }
    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            z[i + j - 1] += x[i] * y[j];
        }
    }
    for (int i = 1; i <= len1 + len2; i++) {
        z[i + 1] += z[i] / 10, z[i] %= 10;
    }
    n = len1 + len2;
    while (n > 1 && !z[n]) {
        n--;
    }
}

inline void solve() {
    for (int i = n; i >= 1; i--) {
        cout << z[i];
    }
    cout << "\n";
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    solve();
    return 0;
}
