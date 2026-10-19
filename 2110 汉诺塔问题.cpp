#include <bits/stdc++.h>
using namespace std;

int n;

inline void input() {
    cin >> n;
}

inline void dfs(int x, int a, int b, int c) {
    if (x == 1) {
        cout << char(a) << "->1->" << char(b) << "\n";
        return;
    }
    dfs(x - 1, a, c, b);
    cout << char(a) << "->" << x << "->" << char(b) << "\n";
    dfs(x - 1, c, b, a);
    return;
}

inline void solve() {
    cout << (1 << n) - 1 << "\n";
    dfs(n, 'a', 'c', 'b');
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    solve();
    return 0;
}
