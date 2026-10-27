#include <bits/stdc++.h>
using namespace std;
const int N = 5e3 + 5;
int n, m, i, j, t;
struct stu {
    int id, s;
} a[N], b[N];
bool cmp(stu x, stu y) {
    if (x.s != y.s) {
        return x.s > y.s;
    }
    return x.id < y.id;
}
signed main() {
    cin >> n >> m;
    for (i = 1; i <= n; i++) {
        cin >> a[i].id >> a[i].s;
    }
    sort(a + 1, a + n + 1, cmp);
    t = a[m].s;
    j = 0;
    for (i = 1; i <= n; i++) {
        if (a[i].s >= t) {
            j++;
            b[j].id = a[i].id, b[j].s = a[i].s;
        }
    }
    cout << t << " " << j << "\n";
    for (i = 1; i <= j; i++) {
        cout << b[i].id << " " << b[i].s << "\n";
    }
    return 0;
}
