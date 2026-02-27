#include <bits/stdc++.h>
// #define int long long
using namespace std;

const int N = 200010;

int n, cnt;
long long ans;

struct node {
    int ls, rs;
    long long s;
} tr[N * 40];

void insert(int& k, int y, int l, int r) {
    if (!k)
        k = ++cnt;
    if (l == r) {
        tr[k].s++;
        return;
    }
    int mid = (l + r) / 2;
    if (mid >= y) {
        insert(tr[k].ls, y, l, mid);
    } else {
        insert(tr[k].rs, y, mid + 1, r);
    }
    tr[k].s = tr[tr[k].ls].s + tr[tr[k].rs].s;
    return;
}

int merge(int k, int k1, int l, int r, long long& sum1, long long& sum2) {
    if (!k || !k1)
        return k + k1;
    if (l == r) {
        tr[k].s += tr[k1].s;
        return k;
    }
    int mid = (l + r) / 2;
    long long k_l = tr[tr[k].ls].s, k1_l = tr[tr[k1].ls].s;
    long long k_r = tr[tr[k].rs].s, k1_r = tr[tr[k1].rs].s;
    sum1 += k_l * k1_r;
    sum2 += k1_l * k_r;
    tr[k].ls = merge(tr[k].ls, tr[k1].ls, l, mid, sum1, sum2);
    tr[k].rs = merge(tr[k].rs, tr[k1].rs, mid + 1, r, sum1, sum2);
    tr[k].s = tr[tr[k].ls].s + tr[tr[k].rs].s;
    return k;
}

int dfs() {
    int x;
    cin >> x;
    int root = 0;
    if (x != 0) {
        insert(root, x, 1, n);
        return root;
    } else {
        int lroot = dfs();
        int rroot = dfs();
        long long sum1 = 0, sum2 = 0;
        root = merge(lroot, rroot, 1, n, sum1, sum2);
        ans += min(sum1, sum2);
        return root;
    }
}

signed main() {
    cin >> n;
    dfs();
    cout << ans;
    return 0;
}
