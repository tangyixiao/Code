#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n, a[N], t[N];

inline void input() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
}

inline void solve() {
    for (int i = 1; i <= n; i++) {
        t[i] = a[i];
    }
    sort(t + 1, t + n + 1);
    int m;
    cin >> m;
    for (int i = 1; i <= n; i++) {
        int p = lower_bound(t + 1, t + n + 1, m - t[i]) - t;
        if (p > n || t[i] + t[p] != m || t[i] >= t[p]) {
            continue;
        }
        cout << t[i] << " " << t[p] << "\n";
        return;
    }
    cout << "No\n";
    return;
}

signed main() {
    input(), solve();
    return 0;
}