#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e4 + 5;
struct node {
    int l, r;
} a[N];
int n;

inline bool cmp(node x, node y) { return x.l < y.l; }

inline void input() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].l >> a[i].r;
    }
    return;
}

inline void solve() {
    input();
    sort(a + 1, a + 1 + n, cmp);
    int l = a[1].l, r = a[1].r;
    for (int i = 2; i <= n; i++) {
        if (a[i].l > r) {
            cout << "no\n";
            return;
        }
        r = max(r, a[i].r);
    }
    cout << l << " " << r << "\n";
    return;
}

signed main() {
    solve();
    return 0;
}