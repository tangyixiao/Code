#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 5;

int n, a[N], b[N];
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

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    msort(1, n);
    cout << ans << "\n";
    return 0;
}
