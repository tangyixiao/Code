#include <bits/stdc++.h>
using namespace std;
const int N = 5e2 + 5;
int fr[N][N], c[N], t = 0;
string nm[N];
int id(string s) {
    for (int k = 1; k <= t; k++) {
        if (nm[k] == s) {
            return k;
        }
    }
    nm[++t] = s;
    return t;
}
signed main() {
    int n, m, i, u, v, ans = 0;
    string s, w;
    cin >> n >> m;
    for (i = 1; i <= m; i++) {
        cin >> s >> w;
        u = id(s), v = id(w);
        if (fr[u][v] == 0) {
            fr[u][v] = 1, fr[v][u] = 1, c[u]++, c[v]++;
        }
    }
    for (i = 1; i <= t; i++) {
        if (c[i] > ans) {
            ans = c[i];
        }
    }
    cout << ans << "\n";
    return 0;
}
