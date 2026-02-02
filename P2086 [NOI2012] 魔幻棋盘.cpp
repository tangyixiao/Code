#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class SegTree {
private:
    int depth, size;
    vector<ll> sum, gc;

    void pull(int idx) {
        sum[idx] = sum[idx << 1] + sum[idx << 1 | 1];
        gc[idx] = gcd(gc[idx << 1], gc[idx << 1 | 1]);
    }

public:
    void build(vector<ll> arr) {
        depth = __lg(arr.size()) + (__builtin_popcount(arr.size()) > 1);
        sum.resize((size = 1 << depth) << 1);
        gc = sum;
        for (int i = 0; i < arr.size(); i++)
            sum[i + size] = gc[i + size] = arr[i];
        for (int i = size - 1; i; i--)
            pull(i);
    }

    void modify(int pos, ll delta) {
        sum[pos += size] += delta;
        gc[pos] += delta;
        for (int i = 1; i <= depth; i++)
            pull(pos >> i);
    }

    ll rangeSum(int l, int r) {
        ll res = 0;
        l += size, r += size;
        while (l < r) {
            if (l & 1)
                res += sum[l++];
            if (r & 1)
                res += sum[--r];
            l >>= 1, r >>= 1;
        }
        return res;
    }

    ll rangeGcd(int l, int r) {
        ll res = 0;
        l += size, r += size;
        while (l < r) {
            if (l & 1)
                res = gcd(res, gc[l++]);
            if (r & 1)
                res = gcd(res, gc[--r]);
            l >>= 1, r >>= 1;
        }
        return res;
    }
};

int main() {
    ios::sync_with_stdio(false);
    int n, m, cx, cy, q;
    cin >> n >> m >> cx >> cy >> q;
    cx--, cy--;

    bool transposed = n > m;
    if (transposed) {
        swap(n, m);
        swap(cx, cy);
    }

    vector<vector<ll>> mat(n, vector<ll>(m));
    if (transposed) {
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                cin >> mat[j][i];
    } else {
        for (auto& row : mat)
            for (auto& val : row)
                cin >> val;
    }

    vector<SegTree> trees(n);
    for (int i = 0; i < n; i++) {
        vector<ll> diff(m);
        adjacent_difference(mat[i].begin(), mat[i].end(), diff.begin());
        trees[i].build(diff);
    }

    while (q--) {
        int type;
        cin >> type;
        if (type) {
            int x1, y1, x2, y2;
            ll delta;
            cin >> x1 >> y1 >> x2 >> y2 >> delta;
            x1--, y1--, x2--, y2--;
            if (transposed) {
                swap(x1, y1);
                swap(x2, y2);
            }
            for (int i = x1; i <= x2; i++) {
                trees[i].modify(y1, delta);
                if (y2 + 1 < m)
                    trees[i].modify(y2 + 1, -delta);
            }
        } else {
            int dx1, dy1, dx2, dy2;
            cin >> dx1 >> dy1 >> dx2 >> dy2;
            if (transposed) {
                swap(dx1, dy1);
                swap(dx2, dy2);
            }
            ll ans = 0;
            for (int i = cx - dx1; i <= cx + dx2; i++) {
                ll rowGcd = gcd(trees[i].rangeGcd(cy - dy1 + 1, cy + dy2 + 1),
                                trees[i].rangeSum(0, cy - dy1 + 1));
                ans = gcd(ans, rowGcd);
            }
            cout << ans << '\n';
        }
    }
    return 0;
}