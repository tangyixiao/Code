#include <bits/stdc++.h>
using namespace std;

const int N = 5005;
struct node {
    int k, s;
} a[N];
int n, m;

signed main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].k >> a[i].s;
    }
    sort(a + 1, a + n + 1, [](node x, node y) {
        if (x.s != y.s) {
            return x.s > y.s;
        }
        return x.k < y.k;
    });
    int p = m * 3 / 2, ln = 0;
    for (int i = 1; i <= n; i++) {
        if (i == p) {
            ln = a[i].s;
        }
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i].s >= ln) {
            cnt++;
        }
    }
    cout << ln << " " << cnt << "\n";
    for (int i = 1; i <= n; i++) {
        if (a[i].s >= ln) {
            cout << a[i].k << " " << a[i].s << "\n";
        }
    }
    return 0;
}
