#include <bits/stdc++.h>
using namespace std;
const int N = 1e2 + 5;
struct node {
    int id, rk;
    double s;
    char t[N];
} a[N];
inline bool cmp(node x, node y) {
    if (x.s != y.s) {
        return x.s > y.s;
    }
    return x.id > y.id;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].id >> a[i].t;
        a[i].s = atof(a[i].t);
    }
    sort(a + 1, a + n + 1, cmp);
    for (int i = 1; i <= n; i++) {
        if (i > 1 && a[i].s == a[i - 1].s) {
            a[i].rk = a[i - 1].rk;
        } else {
            a[i].rk = i;
        }
        cout << a[i].rk << " " << a[i].id << " " << a[i].t << "\n";
    }
    return 0;
}
