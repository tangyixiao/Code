#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
int n, m;
long long a[N], b[N];
long long mx[N * 4];

void build(int o, int l, int r) {
    if (l == r) {
        mx[o] = a[l];
        return;
    }
    int mid = (l + r) / 2;
    build(o * 2, l, mid);
    build(o * 2 + 1, mid + 1, r);
    mx[o] = max(mx[o * 2], mx[o * 2 + 1]);
}

void upd(int o, int l, int r, int p, long long v) {
    if (l == r) {
        mx[o] = v;
        return;
    }
    int mid = (l + r) / 2;
    if (p <= mid) {
        upd(o * 2, l, mid, p, v);
    } else {
        upd(o * 2 + 1, mid + 1, r, p, v);
    }
    mx[o] = max(mx[o * 2], mx[o * 2 + 1]);
}

int fd(int o, int l, int r, int ql, long long v) {
    if (r < ql || mx[o] <= v) {
        return -1;
    }
    if (l == r) {
        return l;
    }
    int mid = (l + r) / 2;
    int k = fd(o * 2, l, mid, ql, v);
    if (k != -1) {
        return k;
    }
    return fd(o * 2 + 1, mid + 1, r, ql, v);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= m; i++) {
        cin >> b[i];
    }
    build(1, 1, n);
    for (int i = 1; i <= m; i++) {
        long long L = 0, h = b[i];
        int s = 1;
        while (s <= n && L < h) {
            int k = fd(1, 1, n, s, L);
            if (k == -1) {
                break;
            }
            long long x = a[k];
            long long e = min(x, h) - L;
            a[k] = x + e;
            L = min(x, h);
            upd(1, 1, n, k, a[k]);
            s = k + 1;
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << a[i] << "\n";
    }
    return 0;
}
