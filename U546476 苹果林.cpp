// Problem: U546476 苹果林
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/U546476?contestId=322549
// Memory Limit: 256 MB
// Time Limit: 2200 ms
#include <bits/stdc++.h>
#define int long long
#define lowbit(x) ((x) & (-x))
#define mid ((l + r) >> 1)
using namespace std;
namespace FastIO {
char buf[1 << 23], *p1 = buf, *p2 = buf;
#define getchar() \
    (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 21, stdin), p1 == p2) ? EOF : *p1++)
inline int read() {
    register int sr = 0;
    register char ch = getchar(), last = 0;
    while (ch < '0' || ch > '9')
        last = ch, ch = getchar();
    while (ch >= '0' && ch <= '9')
        sr = (sr << 1) + (sr << 3) + (ch ^ 48), ch = getchar();
    return last == '-' ? -sr : sr;
}
} // namespace FastIO
using namespace FastIO;
namespace Tangyixiao {

const int N = 5e5 + 5;
int n, q;
string s;
struct node {
    int cntI, cntO, cntIO, cntOI, cntIOI;
    node() : cntI(0ll), cntO(0ll), cntIO(0ll), cntOI(0ll), cntIOI(0ll) {}
    node(char c) {
        cntI = (c == 'I'), cntO = (c == 'O'), cntIO = cntOI = cntIOI = 0ll;
    }
} tree[N << 2];

inline node merge(node a, node b) {
    node res;
    res.cntI = a.cntI + b.cntI, res.cntO = a.cntO + b.cntO, res.cntIO = a.cntIO + b.cntIO + a.cntI * b.cntO, res.cntOI = a.cntOI + b.cntOI + a.cntO * b.cntI, res.cntIOI = a.cntIOI + b.cntIOI + a.cntI * b.cntOI + a.cntIO * b.cntI;
    return res;
}
inline void build(int idx, int l, int r) {
    if (l == r) {
        tree[idx] = node(s[l]);
        return;
    }
    build(idx << 1, l, mid), build(idx << 1 | 1, mid + 1, r);
    tree[idx] = merge(tree[idx << 1], tree[idx << 1 | 1]);
    return;
}

inline void update(int idx, int l, int r, int pos, char c) {
    if (l == r) {
        tree[idx] = node(c);
        return;
    }
    if (pos <= mid) {
        update(idx << 1, l, mid, pos, c);
    } else {
        update(idx << 1 | 1, mid + 1, r, pos, c);
    }
    tree[idx] = merge(tree[idx << 1], tree[idx << 1 | 1]);
    return;
}

inline node query(int idx, int l, int r, int ql, int qr) {
    if (ql <= l && r <= qr) {
        return tree[idx];
    }
    if (qr <= mid) {
        return query(idx << 1, l, mid, ql, qr);
    } else {
        if (ql > mid) {
            return query(idx << 1 | 1, mid + 1, r, ql, qr);
        } else {
            return merge(query(idx << 1, l, mid, ql, qr), query(idx << 1 | 1, mid + 1, r, ql, qr));
        }
    }
}
inline void mian() {
    cin >> n >> q >> s;
    s = " " + s;
    build(1, 1, n);
    for (int op, l, r, x; q--;) {
        char c;
        cin >> op;
        if (op == 1) {
            cin >> x >> c;
            update(1, 1, n, x, c);
        } else {
            cin >> l >> r;
            cout << query(1, 1, n, l, r).cntIOI << "\n";
        }
    }
    return;
}
} // namespace Tangyixiao

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    Tangyixiao::mian();
    // cerr << "I AK IOI\n";
    return 0;
}