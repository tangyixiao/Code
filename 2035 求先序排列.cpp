#include <bits/stdc++.h>
using namespace std;

string a, b;

inline void input() {
    cin >> a >> b;
}

inline void dfs(int l1, int r1, int l2, int r2) {
    if (l1 > r1) {
        return;
    }
    cout << b[r2];
    int k = l1;
    while (a[k] != b[r2]) {
        k++;
    }
    dfs(l1, k - 1, l2, l2 + k - l1 - 1);
    dfs(k + 1, r1, l2 + k - l1, r2 - 1);
}

inline void solve() {
    dfs(0, (int)a.size() - 1, 0, (int)b.size() - 1);
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
