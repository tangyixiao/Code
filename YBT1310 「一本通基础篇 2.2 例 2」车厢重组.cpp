#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 5;
int n, a[N], b[N];
long long ans;

inline void input() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    return;
}

inline void solve(int l, int r) {
    if (l >= r) {
        return;
    }
    int mid = (l + r) >> 1;
    solve(l, mid), solve(mid + 1, r);
    int i = l, j = mid + 1, t = l;
    while (i <= mid && j <= r) {
        if (a[i] <= a[j]) {
            b[t++] = a[i++];
        } else {
            ans += mid - i + 1;
            b[t++] = a[j++];
        }
    }
    while (i <= mid) {
        b[t++] = a[i++];
    }
    while (j <= r) {
        b[t++] = a[j++];
    }
    for (int k = l; k <= r; k++) {
        a[k] = b[k];
    }
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    solve(1, n);
    cout << ans << "\n";
    return 0;
}
