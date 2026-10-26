#include <bits/stdc++.h>
using namespace std;

const int N = 3e4 + 5, M = 5e3 + 5;
int n, m, tot, fa[N], tr[N];

struct node {
    int l, r, c;
} q[M];

bool cmp(node a, node b) {
    return a.r < b.r;
}

int find(int x) {
    return fa[x] == x ? x : fa[x] = find(fa[x]);
}

void add(int x) {
    for (; x <= n; x += x & -x) {
        tr[x]++;
    }
}

int sum(int x) {
    int s = 0;
    for (; x > 0; x -= x & -x) {
        s += tr[x];
    }
    return s;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> q[i].l >> q[i].r >> q[i].c;
    }
    sort(q + 1, q + m + 1, cmp);
    for (int i = 0; i <= n; i++) {
        fa[i] = i;
    }
    for (int i = 1; i <= m; i++) {
        int have = sum(q[i].r) - sum(q[i].l - 1);
        for (; have < q[i].c;) {
            int p = find(q[i].r);
            if (p < q[i].l) {
                break;
            }
            add(p);
            fa[p] = find(p - 1);
            have++, tot++;
        }
    }
    cout << tot << "\n";
    return 0;
}
