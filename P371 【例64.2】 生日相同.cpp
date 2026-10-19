#include <bits/stdc++.h>
using namespace std;

const int N = 200 + 5;
struct node {
    int m, d;
    char s[N];
} a[N];
int n;

signed main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].s >> a[i].m >> a[i].d;
    }
    sort(a + 1, a + n + 1, [](node x, node y) {
        if (x.m != y.m) {
            return x.m < y.m;
        }
        if (x.d != y.d) {
            return x.d < y.d;
        }
        int p = strlen(x.s), q = strlen(y.s);
        return p != q ? p < q : strcmp(x.s, y.s) < 0;
    });
    bool t = false;
    for (int i = 1; i <= n; i++) {
        if (i > 1 && a[i].m == a[i - 1].m && a[i].d == a[i - 1].d) {
            continue;
        }
        if (i + 1 > n || a[i].m != a[i + 1].m || a[i].d != a[i + 1].d) {
            continue;
        }
        t = true, cout << a[i].m << " " << a[i].d;
        for (int j = i; j <= n && a[j].m == a[i].m && a[j].d == a[i].d; j++) {
            cout << " " << a[j].s;
        }
        cout << "\n";
    }
    if (!t) {
        cout << "None\n";
    }
    return 0;
}