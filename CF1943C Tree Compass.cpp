#include <bits/stdc++.h>
using namespace std;

const int N = 2005, M = 4005;
int h[N], t[M], nx[M], ec;
int q[N], d[N], p[N];
int path[N], pc;
int n;

void add(int u, int v) {
    t[++ec] = v;
    nx[ec] = h[u];
    h[u] = ec;
}

void bfs(int s, int &far) {
    int l = 0, r = 0;
    q[r++] = s;
    d[s] = 0;
    p[s] = 0;
    far = s;
    while (l < r) {
        int u = q[l++];
        for (int e = h[u]; e; e = nx[e]) {
            int v = t[e];
            if (v == p[u])
                continue;
            p[v] = u;
            d[v] = d[u] + 1;
            if (d[v] > d[far])
                far = v;
            q[r++] = v;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        if (n == 1) {
            cout << "1\n1 0\n";
            continue;
        }
        fill(h + 1, h + n + 1, 0);
        ec = 0;
        for (int i = 1; i < n; ++i) {
            int u, v;
            cin >> u >> v;
            add(u, v);
            add(v, u);
        }
        int u, v;
        bfs(1, u);
        bfs(u, v);
        pc = 0;
        for (int x = v; x; x = p[x])
            path[++pc] = x;
        reverse(path + 1, path + pc + 1);
        int D = pc - 1;
        if (D % 2 == 0) {
            int c = path[D / 2 + 1];
            int op = D / 2 + 1;
            cout << op << '\n';
            for (int i = 0; i < op; ++i)
                cout << c << ' ' << i << '\n';
        } else {
            int c1 = path[D / 2 + 1];
            int c2 = path[D / 2 + 2];
            int op = (D + 1) / 2 + 1;
            cout << op << '\n';
            for (int i = 0; i <= D - 1; i += 2)
                cout << c1 << ' ' << i << '\n';
            cout << c2 << ' ' << 0 << '\n';
        }
    }
    return 0;
}