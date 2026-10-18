#include <bits/stdc++.h>
using namespace std;

const int N = 1e2 + 5;

int n, a, b, k;
double h[N], g[N], t;

inline void input() {
    cin >> n;
    a = 0, b = 0;
    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s >> t;
        if (s[0] == 'm') {
            h[++a] = t;
        } else {
            g[++b] = t;
        }
    }
    for (int i = 1; i <= a; i++) {
        for (int j = i + 1; j <= a; j++) {
            if (h[j] < h[i]) {
                swap(h[i], h[j]);
            }
        }
    }
    for (int i = 1; i <= b; i++) {
        for (int j = i + 1; j <= b; j++) {
            if (g[j] > g[i]) {
                swap(g[i], g[j]);
            }
        }
    }
}

inline void solve() {
    cout << fixed << setprecision(2);
    for (int i = 1; i <= a; i++) {
        cout << h[i] << " ";
    }
    for (int i = 1; i <= b; i++) {
        cout << g[i] << (i < b ? " " : "\n");
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