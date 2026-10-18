#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int a[N], b[N], n;
long long ans;

inline void msort(int l, int r) {
    if (l >= r) {
        return;
    }
    int mid = (l + r) >> 1;
    msort(l, mid), msort(mid + 1, r);
    int i = l, j = mid + 1, k = l;
    for (; i <= mid && j <= r;) {
        if (a[i] <= a[j]) {
            b[k++] = a[i++];
        } else {
            b[k++] = a[j++], ans += mid - i + 1;
        }
    }
    for (; i <= mid; ++i) {
        b[k++] = a[i];
    }
    for (; j <= r; ++j) {
        b[k++] = a[j];
    }
    for (int p = l; p <= r; ++p) {
        a[p] = b[p];
    }
}

inline void input() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
}

inline void solve() {
    msort(1, n);
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