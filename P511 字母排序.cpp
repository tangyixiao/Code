#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
int n, l, a[N], c;
string ans;

inline int f(int x) {
    return x == 0 || x == 4 || x == 8 || x == 14 || x == 20;
}

inline void input() {
    cin >> l >> n;
    char ch;
    while (cin >> ch) {
        if (ch >= 'a' && ch <= 'z') {
            a[c++] = ch - 'a';
        }
    }
    sort(a, a + c);
}

inline void dfs(int p, int len, int v, int k) {
    if (len == l) {
        if (v && k >= 2) {
            cout << ans << "\n";
        }
        return;
    }
    for (int i = p; i < c; i++) {
        ans += char('a' + a[i]);
        dfs(i + 1, len + 1, v + f(a[i]), k + !f(a[i]));
        ans.erase(ans.size() - 1);
    }
    return;
}

inline void solve() {
    dfs(0, 0, 0, 0);
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    solve();
    return 0;
}
