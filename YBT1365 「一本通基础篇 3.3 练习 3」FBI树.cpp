#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
int n;
char s[N];

inline void input() {
    cin >> n >> s;
}

inline void dfs(int l, int r) {
    int x = 0, y = 0;
    for (int i = l; i <= r; i++) {
        if (s[i] == '0') {
            x = 1;
        } else {
            y = 1;
        }
    }
    char c = x && y ? 'F' : (x ? 'B' : 'I');
    if (l == r) {
        cout << c;
        return;
    }
    int m = (l + r) / 2;
    dfs(l, m);
    dfs(m + 1, r);
    cout << c;
    return;
}

inline void solve() {
    dfs(0, (1 << n) - 1);
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
