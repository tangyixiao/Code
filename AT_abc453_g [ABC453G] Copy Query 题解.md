# 思路解析

这其实就是可持久化线段树的模板题。

操作 $2$ 和 $3$ 都是比较平凡的单点修改和区间查询的朴素数据结构维护操作，重点是如何来看操作 $1$。

操作 $1$ 就是把序列 $X$ 复制为序列 $Y$，想象到暴力的复杂度为 $O(QM)$，过不了一点。

这个很像引用操作，操作 $2$ 和 $3$ 如果对 $X$ 或 $Y$ 进行了修改，那么就会衍生出另一个版本，就会分裂。

这个旧版本保持不变，修改产生新版本的思想就是可持续化数据结构的思想。

具体的，对于操作 $1$，我们只需要把 $X$ 的根节点的引用复制到 $Y$ 的根节点即可。

时空复杂度 $O(Q \log M)$。

# 代码实现

```cpp
namespace TANGYIXIAO {
const int N = 2e5 + 5, M = 4e6 + 5;
int n, m, q, rt[N], lc[M], rc[M], sum[M], tot;
inline int update(int p, int l, int r, int id, int v) {
    int c = ++tot;
    if (l == r) {
        sum[c] = v;
        return c;
    }
    lc[c] = lc[p], rc[c] = rc[p];
    int mid = (l + r) >> 1;
    if (id <= mid) {
        lc[c] = update(lc[p], l, mid, id, v);
    } else {
        rc[c] = update(rc[p], mid + 1, r, id, v);
    }
    sum[c] = sum[lc[c]] + sum[rc[c]];
    return c;
}

inline int query(int nd, int l, int r, int ql, int qr) {
    if (!nd || ql > r || qr < l) {
        return 0;
    }
    if (ql <= l && r <= qr) {
        return sum[nd];
    }
    int mid = (l + r) >> 1, res = 0;
    if (ql <= mid) {
        res += query(lc[nd], l, mid, ql, qr);
    }
    if (qr > mid) {
        res += query(rc[nd], mid + 1, r, ql, qr);
    }
    return res;
}

inline void solve(int Task_Id) {
    cin >> n >> m >> q;
    for (int op, x, y, z, l, r; q--;) {
        cin >> op;
        if (op == 1) {
            cin >> x >> y;
            rt[x] = rt[y];
        } else if (op == 2) {
            cin >> x >> y >> z;
            rt[x] = update(rt[x], 1, m, y, z);
        } else {
            cin >> x >> l >> r;
            cout << query(rt[x], 1, m, l, r) << '\n';
        }
    }
}
} // namespace TANGYIXIAO
```
