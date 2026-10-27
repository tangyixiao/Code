#include <bits/stdc++.h>
using namespace std;
const int N = 2e2 + 5;
int v[N], d[N], q[N];
int n, A, B, i, hd, tl;
signed main() {
    cin >> n >> A >> B;
    for (i = 1; i <= n; i++) {
        cin >> v[i];
    }
    for (i = 1; i <= n; i++) {
        d[i] = -1;
    }
    hd = 0, tl = 0, d[A] = 0, q[tl++] = A;
    while (hd < tl) {
        int u = q[hd++];
        if (u == B) {
            break;
        }
        int w = u + v[u];
        if (w >= 1 && w <= n && d[w] == -1) {
            d[w] = d[u] + 1, q[tl++] = w;
        }
        w = u - v[u];
        if (w >= 1 && w <= n && d[w] == -1) {
            d[w] = d[u] + 1, q[tl++] = w;
        }
    }
    cout << d[B] << "\n";
    return 0;
}
