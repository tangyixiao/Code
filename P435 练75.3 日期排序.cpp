#include <bits/stdc++.h>
using namespace std;

const int N = 1e2 + 5;

char s[N][N];
int n, a[N];

inline void input() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
        int y, m, d;
        sscanf(s[i], "%d/%d/%d", &m, &d, &y);
        a[i] = y * 1e4 + m * 1e2 + d;
    }
}

inline void solve() {
    int p[N];
    for (int i = 0; i < n; i++) {
        p[i] = i;
    }
    sort(p, p + n, [](int x, int y) { return a[x] < a[y]; });
    for (int i = 0; i < n; i++) {
        cout << s[p[i]] << "\n";
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