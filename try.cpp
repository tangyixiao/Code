int lg[N], f[MAXLOG][N];

void build(int n) {
    lg[1] = 0;
    for (int i = 2; i <= n; i++)
        lg[i] = lg[i / 2] + 1;

    for (int i = 1; i <= n; i++)
        f[0][i] = a[i];

    for (int j = 1; j <= lg[n]; j++)
        for (int i = 1; i + (1 << j) - 1 <= n; i++)
            f[j][i] = max(f[j - 1][i],
                          f[j - 1][i + (1 << (j - 1))]);
}

int query(int l, int r) {
    int k = lg[r - l + 1];
    return max(f[k][l], f[k][r - (1 << k) + 1]);
}



// 假设 n <= 1000000，点编号为 1..n
const int N = 1000005, LOG = 20;
vector<int> g[N];
int fa[LOG + 1][N], dep[N];

void build(int root) {
    queue<int> q;
    q.push(root);
    dep[root] = 1;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : g[u]) {
            if (v == fa[0][u]) continue;

            dep[v] = dep[u] + 1;
            fa[0][v] = u;
            for (int j = 1; j <= LOG; j++)
                fa[j][v] = fa[j - 1][fa[j - 1][v]];

            q.push(v);
        }
    }
}

int lca(int u, int v) {
    if (dep[u] < dep[v]) swap(u, v);

    // 让 u、v 深度相同
    int d = dep[u] - dep[v];
    for (int j = LOG; j >= 0; j--)
        if (d & (1 << j))
            u = fa[j][u];

    if (u == v) return u;

    // 一起向上跳，停在 LCA 的下一层
    for (int j = LOG; j >= 0; j--) {
        if (fa[j][u] != fa[j][v]) {
            u = fa[j][u];
            v = fa[j][v];
        }
    }

    return fa[0][u];
}



long long x, y;
long long d = exgcd(a, m, x, y);

if (d == 1) {
    x = (x % m + m) % m;
    // x 就是逆元
} else {
    // gcd(a, m) != 1，逆元不存在
}


long long exgcd(long long a, long long b,
                long long &x, long long &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }

    long long d = exgcd(b, a % b, x, y);

    long long t = x;
    x = y;
    y = t - a / b * y;

    return d;
}