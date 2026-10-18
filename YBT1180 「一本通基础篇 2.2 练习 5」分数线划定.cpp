#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
struct node {
    int k, s;
} a[N];

int n, m, c, l;

inline bool cmp(node x, node y) { return x.s != y.s ? x.s > y.s : x.k < y.k; }

inline void input() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].k >> a[i].s;
    }
    return;
}

inline void solve() {
    sort(a + 1, a + n + 1, cmp);
    l = a[m * 3 / 2].s;
    for (int i = 1; i <= n; i++) {
        if (a[i].s >= l) {
            c++;
        }
    }
    cout << l << " " << c << "\n";
    for (int i = 1; i <= c; i++) {
        cout << a[i].k << " " << a[i].s << "\n";
    }
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    solve();
    return 0;
}
