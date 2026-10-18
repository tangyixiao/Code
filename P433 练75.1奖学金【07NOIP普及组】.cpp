#include <bits/stdc++.h>
using namespace std;

const int N = 3e2 + 5;

int n;
struct node {
    int id, a, b, c, s;
} t[N];

bool cmp(node x, node y) {
    if (x.s != y.s) {
        return x.s > y.s;
    }
    if (x.a != y.a) {
        return x.a > y.a;
    }
    return x.id < y.id;
}

inline void input() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> t[i].a >> t[i].b >> t[i].c, t[i].id = i, t[i].s = t[i].a + t[i].b + t[i].c;
    }
}

inline void solve() {
    sort(t + 1, t + n + 1, cmp);
    for (int i = 1; i <= 5; i++) {
        cout << t[i].id << " " << t[i].s << "\n";
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
