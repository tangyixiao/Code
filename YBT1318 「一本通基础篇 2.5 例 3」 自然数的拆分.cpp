#include <bits/stdc++.h>
using namespace std;

const int N = 1e2 + 5;
int n, a[N], l;

inline void input() {
    cin >> n;
}

inline void dfs(int s, int p) {
    if (s == 0) {
        cout << n << "=";
        for (int i = 0; i < l; i++) {
            cout << a[i];
            if (i < l - 1) {
                cout << "+";
            }
        }
        cout << "\n";
        return;
    }
    for (int i = p; i <= s; i++) {
        if (i == s && l == 0) {
            continue;
        }
        a[l++] = i;
        dfs(s - i, i);
        l--;
    }
}

inline void solve() {
    dfs(n, 1);
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    solve();
    return 0;
}