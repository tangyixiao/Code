#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
const int M = 2e5 + 5;
int n, i, u, v, p;
struct edge {
    int a, b;
} e[M];
bool cmp(edge x, edge y) {
    if (x.a != y.a) {
        return x.a < y.a;
    }
    return x.b < y.b;
}
signed main() {
    cin >> n;
    for (i = 1; i <= n; i++) {
        cin >> u >> v;
        e[i * 2 - 1].a = u, e[i * 2 - 1].b = v;
        e[i * 2].a = v, e[i * 2].b = u;
    }
    sort(e + 1, e + 2 * n + 1, cmp);
    for (i = 1; i <= 2 * n; i = p) {
        cout << e[i].a << ":";
        int first = 1;
        for (p = i; p <= 2 * n && e[p].a == e[i].a; p++) {
            if (p > i && e[p].b == e[p - 1].b) {
                continue;
            }
            if (!first) {
                cout << " ";
            }
            cout << e[p].b;
            first = 0;
        }
        cout << "\n";
    }
    return 0;
}
