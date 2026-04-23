// Problem: U546474 向日葵村
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/U546474?contestId=322549
// Memory Limit: 128 MB
// Time Limit: 1000 ms

#include <bits/stdc++.h>
#define int long long
#define lowbit(x) ((x) & (-x))
using namespace std;
const int N = 1e6 + 5;
int n, q, a[N], b[N], bit[N];

inline void add(int idx, int val) {
    while (idx <= n - 1) {
        bit[idx] += val;
        idx += lowbit(idx);
    }
}

inline int sum(int idx) {
    int s = 0;
    while (idx > 0) {
        s += bit[idx];
        idx -= lowbit(idx);
    }
    return s;
}
inline void mian() {
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n - 1; ++i) {
        b[i] = a[i + 1] - a[i];
    }
    for (int i = 1; i <= n - 1; ++i) {
        if (b[i] < 0) {
            add(i, 1);
        }
    }
    if (!(n - 1)) {

        for (int op, l, r, x; q--;) {
            cin >> op >> l >> r;
            if (r == n + 1) {
                r = n;
            }
            if (!(op & 1)) {
                cin >> x;
            } else {
                cout << "Yes\n";
            }
        }
        return;
    }
    for (int op, l, r, x; q--;) {
        cin >> op >> l >> r;
        r = min(r, n);
        if (op & 1) {
            cin >> x;
            if (l > 1) {
                int la = b[l - 1];
                b[l - 1] += x;
                if (la < 0 && b[l - 1] >= 0) {
                    add(l - 1, -1);
                } else {
                    if (la >= 0 && b[l - 1] < 0) {
                        add(l - 1, 1);
                    }
                }
            }

            if (r < n) {
                int la = b[r];
                b[r] -= x;
                if (la < 0 && b[r] >= 0) {
                    add(r, -1);
                } else {
                    if (la >= 0 && b[r] < 0) {
                        add(r, 1);
                    }
                }
            }
        } else {
            if (!(l - r)) {
                cout << "Yes\n";
            } else {
                cout << ((sum(r - 1) - sum(l - 1)) ? "No\n" : "Yes\n");
            }
        }
    }
    return;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    mian();
    return 0;
}
