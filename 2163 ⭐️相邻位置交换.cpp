#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 5;

int n, a[N], t[N];
long long ans;

inline void mrg(int l, int m, int r) {
    int i = l, j = m + 1, k = l;
    for (; i <= m && j <= r;) {
        if (a[i] <= a[j]) {
            t[k++] = a[i++];
        } else {
            t[k++] = a[j++], ans += m - i + 1;
        }
    }
    for (; i <= m;) {
        t[k++] = a[i++];
    }
    for (; j <= r;) {
        t[k++] = a[j++];
    }
    for (int p = l; p <= r; p++) {
        a[p] = t[p];
    }
}

inline void srt(int l, int r) {
    if (l >= r) {
        return;
    }
    int m = (l + r) / 2;
    srt(l, m), srt(m + 1, r), mrg(l, m, r);
}

inline void input() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
}

inline void solve() {
    ans = 0;
    srt(1, n);
    cout << ans << "\n";
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    solve();
    return 0;
}