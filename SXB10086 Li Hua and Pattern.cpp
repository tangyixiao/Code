#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;

int t, n, k;
int a[N];

inline void input() {
    cin >> t;
}

inline void solve() {
    while (t--) {
        cin >> n >> k;
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> a[i * n + j];
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int x = i * n + j, y = (n - 1 - i) * n + (n - 1 - j);
                if (x < y && a[x] != a[y]) {
                    cnt++;
                }
            }
        }
        cout << (k >= cnt && (k - cnt) % 2 == 0 ? "YES" : "NO") << "\n";
    }
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    solve();
    return 0;
}
