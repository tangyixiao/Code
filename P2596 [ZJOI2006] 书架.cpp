#include <algorithm>
#include <cstdio>
using namespace std;

const int N = 80005;
int ch[N][2], fa[N], sz[N], val[N], pos[N], tot, root;
int a[N];

void pu(int x) { sz[x] = sz[ch[x][0]] + sz[ch[x][1]] + 1; }

int bd(int l, int r) {
    if (l > r)
        return 0;
    int m = (l + r) >> 1;
    int x = ++tot;
    val[x] = a[m];
    pos[a[m]] = x;
    int ls = bd(l, m - 1), rs = bd(m + 1, r);
    ch[x][0] = ls;
    if (ls)
        fa[ls] = x;
    ch[x][1] = rs;
    if (rs)
        fa[rs] = x;
    pu(x);
    return x;
}

void rot(int x) {
    int y = fa[x], z = fa[y];
    int k = (ch[y][1] == x);
    if (z)
        ch[z][ch[z][1] == y] = x;
    fa[x] = z;
    ch[y][k] = ch[x][k ^ 1];
    if (ch[x][k ^ 1])
        fa[ch[x][k ^ 1]] = y;
    ch[x][k ^ 1] = y;
    fa[y] = x;
    pu(y);
    pu(x);
}

void spl(int x, int g) {
    while (fa[x] != g) {
        int y = fa[x], z = fa[y];
        if (z != g)
            rot(((ch[y][1] == x) ^ (ch[z][1] == y)) ? x : y);
        rot(x);
    }
    if (!g)
        root = x;
}

int kth(int k) {
    int u = root;
    while (u) {
        int l = sz[ch[u][0]];
        if (k <= l)
            u = ch[u][0];
        else if (k == l + 1)
            return u;
        else
            k -= l + 1, u = ch[u][1];
    }
    return 0;
}

int pre(int x) {
    spl(x, 0);
    int u = ch[x][0];
    if (!u)
        return 0;
    while (ch[u][1])
        u = ch[u][1];
    return u;
}

int nxt(int x) {
    spl(x, 0);
    int u = ch[x][1];
    if (!u)
        return 0;
    while (ch[u][0])
        u = ch[u][0];
    return u;
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    root = bd(1, n);
    char op[10];
    int s, t;
    while (m--) {
        scanf("%s%d", op, &s);
        if (op[0] == 'T') {
            int x = pos[s];
            spl(x, 0);
            int L = ch[x][0], R = ch[x][1];
            if (!L)
                continue;
            ch[x][0] = 0;
            if (!R) {
                ch[x][1] = L;
                fa[L] = x;
                spl(L, 0);
            } else {
                int y = R;
                while (ch[y][0])
                    y = ch[y][0];
                ch[y][0] = L;
                fa[L] = y;
                spl(y, 0);
            }
            pu(x);
        } else if (op[0] == 'B') {
            int x = pos[s];
            spl(x, 0);
            int L = ch[x][0], R = ch[x][1];
            if (!R)
                continue;
            ch[x][1] = 0;
            if (!L) {
                ch[x][0] = R;
                fa[R] = x;
                spl(R, 0);
            } else {
                int y = L;
                while (ch[y][1])
                    y = ch[y][1];
                ch[y][1] = R;
                fa[R] = y;
                spl(y, 0);
            }
            pu(x);
        } else if (op[0] == 'I') {
            scanf("%d", &t);
            if (t == 0)
                continue;
            int x = pos[s];
            if (t == 1) {
                int y = nxt(x);
                swap(val[x], val[y]);
                swap(pos[val[x]], pos[val[y]]);
                spl(y, 0);
            } else {
                int y = pre(x);
                swap(val[x], val[y]);
                swap(pos[val[x]], pos[val[y]]);
                spl(y, 0);
            }
        } else if (op[0] == 'A') {
            int x = pos[s];
            spl(x, 0);
            printf("%d\n", sz[ch[x][0]]);
        } else if (op[0] == 'Q') {
            int x = kth(s);
            printf("%d\n", val[x]);
            spl(x, 0);
        }
    }
    return 0;
}