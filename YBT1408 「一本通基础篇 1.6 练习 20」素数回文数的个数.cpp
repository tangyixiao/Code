#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int n;
bool p[N];

inline void input() { cin >> n; }

inline void solve() {
    p[0] = p[1] = true;
    for (int i = 2; 1LL * i * i <= n; ++i) {
        if (!p[i]) {
            for (int j = i * i; j <= n; j += i) {
                p[j] = true;
            }
        }
    }
    int ans = 0;
    for (int i = 11; i <= n; ++i) {
        if (p[i]) {
            continue;
        }
        int x = i, y = 0;
        while (x) {
            y = y * 10 + x % 10;
            x /= 10;
        }
        if (y == i) {
            ++ans;
        }
    }
    cout << ans << "\n";
    return;
}

signed main() {
    input();
    solve();
    return 0;
}