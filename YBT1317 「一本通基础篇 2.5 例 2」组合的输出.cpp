#include <bits/stdc++.h>
using namespace std;

const int N = 1e2 + 5;
int n, r, k, a[N];

inline void input() { cin >> n >> r; }

inline void dfs(int x) {
    if (k == r) {
        for (int i = 1; i <= r; ++i) {
            cout << setw(3) << a[i];
        }
        cout << "\n";
        return;
    }
    for (int i = x; i <= n; ++i) {
        a[++k] = i;
        dfs(i + 1);
        --k;
    }
    return;
}

inline void solve() {
    dfs(1);
    return;
}

signed main() {
    input();
    solve();
    return 0;
}