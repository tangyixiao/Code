#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int n, a[N], f[N];
long long ans;

inline void input() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
}

inline void merge(int l, int m, int r) {
    int i = l, j = m + 1, k = l;
    while (i <= m && j <= r) {
        if (a[i] <= a[j]) {
            f[k++] = a[i++];
        } else {
            ans += m - i + 1;
            f[k++] = a[j++];
        }
    }
    for (; i <= m; ++i) {
        f[k++] = a[i];
    }
    for (; j <= r; ++j) {
        f[k++] = a[j];
    }
    for (int p = l; p <= r; ++p) {
        a[p] = f[p];
    }
}

inline void solve(int l, int r) {
    if (l >= r) {
        return;
    }
    int m = (l + r) / 2;
    solve(l, m);
    solve(m + 1, r);
    merge(l, m, r);
    return;
}

signed main() {
    input();
    solve(1, n);
    cout << ans << "\n";
    return 0;
}