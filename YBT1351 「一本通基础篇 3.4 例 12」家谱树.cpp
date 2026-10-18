#include <bits/stdc++.h>
using namespace std;

const int N = 1e2 + 5;
int n, sn[N][N], c[N], ind[N], st[N], top;

inline void input() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int x;
        while (cin >> x && x) {
            sn[i][++c[i]] = x;
            ind[x]++;
        }
    }
}

inline void solve() {
    for (int i = 1; i <= n; i++) {
        if (ind[i] == 0) {
            st[++top] = i;
        }
    }
    bool fst = 1;
    while (top) {
        int u = st[top--];
        cout << (fst ? "" : " ") << u;
        fst = 0;
        for (int j = c[u]; j >= 1; j--) {
            if (--ind[sn[u][j]] == 0) {
                st[++top] = sn[u][j];
            }
        }
    }
    cout << "\n";
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    solve();
    return 0;
}
