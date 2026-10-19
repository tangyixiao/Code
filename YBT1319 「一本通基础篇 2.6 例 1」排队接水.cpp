#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
int n, t[N], p[N];

inline void input() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> t[i];
        p[i] = i;
    }
}

inline void solve() {
    sort(p + 1, p + n + 1, [](int x, int y) { return t[x] != t[y] ? t[x] < t[y] : x < y; });
    double s = 0;
    for (int i = 1; i <= n; i++) {
        cout << p[i] << (i == n ? "\n" : " ");
        s += (double)t[p[i]] * (n - i + 1);
    }
    cout << fixed << setprecision(2) << s / n << "\n";
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    solve();
    return 0;
}