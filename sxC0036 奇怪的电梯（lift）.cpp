#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;

int n, a, b, i, u, v;
int k[N], d[N], q[N];

signed main() {
    cin >> n >> a >> b;
    for (i = 1; i <= n; i++) {
        cin >> k[i];
        d[i] = -1;
    }
    int h = 0, t = 0;
    q[t++] = a, d[a] = 0;
    for (; h < t;) {
        u = q[h++];
        v = u + k[u];
        if (v >= 1 && v <= n && d[v] < 0) {
            d[v] = d[u] + 1, q[t++] = v;
        }
        v = u - k[u];
        if (v >= 1 && v <= n && d[v] < 0) {
            d[v] = d[u] + 1, q[t++] = v;
        }
    }
    cout << d[b] << "\n";
    return 0;
}
