#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 5;

int a[7], u[N], ans, lb;

inline void dfs(int k, int c) {
    if (c >= ans) {
        return;
    }
    if (k == 0) {
        ans = c;
        return;
    }
    if (!a[k]) {
        dfs(k - 1, c);
        return;
    }
    a[k]--;
    for (int i = 1; i <= c; ++i) {
        if (u[i] + k * k <= 36) {
            u[i] += k * k;
            dfs(k, c);
            u[i] -= k * k;
        }
    }
    if (c + 1 < ans) {
        u[c + 1] = k * k;
        dfs(k, c + 1);
    }
    a[k]++;
    return;
}

inline void input() {
    for (int i = 1; i <= 6; ++i) {
        cin >> a[i];
    }
    while (a[1] || a[2] || a[3] || a[4] || a[5] || a[6]) {
        ans = a[1] + a[2] + a[3] + a[4] + a[5] + a[6], lb = 1;
        for (int i = 1; i <= 6; ++i) {
            lb += (a[i] * i * i + 35) / 36 - 1;
        }
        ans = max(ans, lb);
        dfs(6, 0);
        cout << ans << "\n";
        for (int i = 1; i <= 6; ++i) {
            cin >> a[i];
        }
    }
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    input();
    return 0;
}
