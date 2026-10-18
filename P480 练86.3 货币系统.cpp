#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 5;

char l[N];
int n, m, a[N], f[N];

inline void input() {
    cin >> n >> m;
    cin.getline(l, sizeof(l));
    for (int i = 0; i < n; i++) {
        cin.getline(l, sizeof(l));
        char *p = strstr(l, "//");
        if (p) {
            *p = '\0';
        }
        a[i] = atoi(l);
    }
}

inline void solve() {
    f[0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = a[i]; j <= m; j++) {
            f[j] += f[j - a[i]];
        }
    }
    cout << f[m] << "\n";
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    solve();
    return 0;
}