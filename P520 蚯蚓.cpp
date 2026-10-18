#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
const int M = 7e6 + 5;

int n, m, q, u, v, t, i, pa, h1, h2, l1, l2;
int a[N], b1[M], b2[M];

inline int gm() {
    int x1 = h1 <= l1 ? b1[h1] : INT_MIN;
    int x2 = h2 <= l2 ? b2[h2] : INT_MIN;
    int x3 = pa <= n ? a[pa] : INT_MIN;
    int r = max(x1, max(x2, x3));
    if (r == x3) {
        pa++;
    } else if (r == x2) {
        h2++;
    } else {
        h1++;
    }
    return r;
}

signed main() {
    cin >> n >> m >> q >> u >> v >> t;
    for (i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1, greater<int>());
    pa = h1 = h2 = 1, l1 = l2 = 0;
    for (i = 1; i <= m; i++) {
        int x = gm() + (i - 1) * q, y = (int)((long long)u * x / v);
        b1[++l1] = x - y - i * q;
        b2[++l2] = y - i * q;
        if (i % t == 0) {
            cout << x << (i + t <= m ? " " : "\n");
        }
    }
    if (m % t) {
        cout << "\n";
    }
    for (i = 1; i <= n + m; i++) {
        int x = gm() + m * q;
        if (i % t == 0) {
            cout << x << (i + t <= n + m ? " " : "\n");
        }
    }
    if ((n + m) % t) {
        cout << "\n";
    }
    return 0;
}