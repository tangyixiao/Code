#include <bits/stdc++.h>
using namespace std;

const int N = 1e2 + 5;
struct node {
    string s;
    int v;
} a[N];

inline bool cmp(node x, node y) {
    if (x.v != y.v) {
        return x.v > y.v;
    }
    return x.s < y.s;
}

signed main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].s >> a[i].v;
    }
    sort(a + 1, a + n + 1, cmp);
    for (int i = 1; i <= n; i++) {
        cout << a[i].s << " " << a[i].v << "\n";
    }
    return 0;
}
