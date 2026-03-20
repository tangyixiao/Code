#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

const int MAXN = 1005;
const int MAXM = 300005;
const int MAXK = 10005;

struct Edge {
    int u, v, w, id;
} e[MAXM];

bool cmp(const Edge &a, const Edge &b) {
    return a.w > b.w;
}

int n, m, k;
int parent[MAXK][MAXN];
int sz[MAXK][MAXN];
int cur[MAXN][MAXN];
int ans[MAXM];

int find(int j, int x) {
    if (parent[j][x] != x)
        parent[j][x] = find(j, parent[j][x]);
    return parent[j][x];
}

int main() {
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= m; ++i) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        e[i] = {a, b, c, i};
    }
    sort(e + 1, e + m + 1, cmp);

    for (int j = 1; j <= k; ++j) {
        for (int i = 1; i <= n; ++i) {
            parent[j][i] = i;
            sz[j][i] = 1;
        }
    }

    for (int i = 1; i <= n; ++i)
        for (int j = i + 1; j <= n; ++j)
            cur[i][j] = 1;

    for (int i = 1; i <= m; ++i) {
        int u = e[i].u, v = e[i].v, id = e[i].id;
        if (u > v)
            swap(u, v);

        int j = cur[u][v];

        while (j <= k && find(j, u) == find(j, v))
            ++j;

        if (j > k) {
            ans[id] = 0;
            continue;
        }

        ans[id] = j;

        int ru = find(j, u), rv = find(j, v);
        if (ru == rv)
            continue;

        if (sz[j][ru] > sz[j][rv])
            swap(ru, rv);

        vector<int> vec_u, vec_v;
        for (int x = 1; x <= n; ++x) {
            if (find(j, x) == ru)
                vec_u.push_back(x);
            if (find(j, x) == rv)
                vec_v.push_back(x);
        }

        parent[j][ru] = rv;
        sz[j][rv] += sz[j][ru];

        for (int x : vec_u) {
            for (int y : vec_v) {
                int a = x, b = y;
                if (a > b)
                    swap(a, b);
                if (cur[a][b] == j) {
                    int nxt = j + 1;
                    while (nxt <= k && find(nxt, a) == find(nxt, b))
                        ++nxt;
                    cur[a][b] = nxt;
                }
            }
        }
    }

    for (int i = 1; i <= m; ++i)
        printf("%d\n", ans[i]);

    return 0;
}