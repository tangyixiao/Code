#include <bits/stdc++.h>
using namespace std;

const int N = 1e2 + 5;

int n, i, j, u, e, p, q, a, bi;
int L[N], U[N], V[N], S[N], T[N], pos[N], p3[N], fr[4], to[4];
long long ans;
vector<long long> d;
priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> h;

signed main() {
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        char x[N], y[N];
        scanf("%d %d %d %s %s", &L[i], &U[i], &V[i], x, y);
        S[i] = x[0] == 'Y' ? 0 : x[0] == 'Z' ? 1
                                             : 2;
        T[i] = y[0] == 'Y' ? 0 : y[0] == 'Z' ? 1
                                             : 2;
    }
    fr[0] = 0, to[0] = 1, fr[1] = 1, to[1] = 0, fr[2] = 1, to[2] = 2, fr[3] = 2, to[3] = 1;
    p3[0] = 1;
    for (i = 1; i <= n; i++) {
        p3[i] = p3[i - 1] * 3;
    }
    u = 0, a = 0;
    for (i = 0; i < n; i++) {
        u += S[i] * p3[i];
        a += T[i] * p3[i];
    }
    d.assign(p3[n], 1ll << 62);
    d[u] = 0;
    h.push(make_pair(0ll, u));
    while (!h.empty()) {
        e = h.top().first;
        u = h.top().second;
        h.pop();
        if (d[u] != e) {
            continue;
        }
        if (u == a) {
            printf("%lld\n", e % 1000000007);
            return 0;
        }
        bi = u;
        for (i = 0; i < n; i++) {
            pos[i] = bi % 3;
            bi /= 3;
        }
        for (j = 0; j < 4; j++) {
            p = fr[j], q = to[j];
            bi = -1;
            for (i = 0; i < n; i++) {
                if (pos[i] == p || pos[i] == q) {
                    if (bi < 0 || L[i] > L[bi]) {
                        bi = i;
                    }
                }
            }
            if (bi < 0 || pos[bi] != p) {
                continue;
            }
            int v = u + (q - p) * p3[bi];
            long long w = p + q == 1 ? U[bi] : V[bi];
            if (d[v] > e + w) {
                d[v] = e + w;
                h.push(make_pair(d[v], v));
            }
        }
    }
    printf("-1\n");
    return 0;
}