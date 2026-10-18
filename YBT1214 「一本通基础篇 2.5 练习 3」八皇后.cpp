#include <bits/stdc++.h>
using namespace std;

int c[9], n, k, cnt;
char ans[20];

inline void dfs(int r) {
    if (r == 9) {
        if (++cnt == k) {
            for (int i = 1; i <= 8; ++i) {
                ans[i] = c[i] + '0';
            }
            ans[9] = 0;
        }
        return;
    }
    for (int i = 1; i <= 8; ++i) {
        bool ok = 1;
        for (int j = 1; j < r; ++j) {
            if (c[j] == i || r - j == i - c[j] || r - j == c[j] - i) {
                ok = 0;
            }
        }
        if (!ok) {
            continue;
        }
        c[r] = i;
        dfs(r + 1);
    }
}

inline void input() {
    cin >> n;
    while (n--) {
        cin >> k;
        cnt = 0;
        dfs(1);
        cout << ans + 1 << "\n";
    }
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    input();
    return 0;
}
