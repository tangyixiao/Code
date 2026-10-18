#include <bits/stdc++.h>
using namespace std;

const int N = 805;
int n, p, c;
int cow[N], d[N][N], cnt[N];

inline void input() {
    cin >> n >> p >> c;
    for (int i = 1; i <= n; i++) {
        cin >> cow[i];
        cnt[cow[i]]++;
    }
    for (int i = 1; i <= p; i++) {
        for (int j = 1; j <= p; j++) {
            d[i][j] = i == j ? 0 : 1e6;
        }
    }
    for (int i = 1; i <= c; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        if (w < d[a][b]) {
            d[a][b] = d[b][a] = w;
        }
    }
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    int ans = 1 << 30;
    for (int i = 1; i <= p; i++) {
        bool ok = true;
        for (int j = 1; j <= p; j++) {
            if (cnt[j] > 0 && d[i][j] >= 1e6) {
                ok = false;
                break;
            }
        }
        if (!ok) {
            continue;
        }
        int s = 0;
        for (int k = 1; k <= n; k++) {
            s += d[i][cow[k]];
        }
        ans = min(ans, s);
    }
    cout << ans << "\n";
    return 0;
}