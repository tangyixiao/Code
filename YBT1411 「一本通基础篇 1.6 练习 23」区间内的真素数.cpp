#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int m, n, cnt;
bool p[N];

inline void input() { cin >> m >> n; }

inline void solve() {
    p[0] = p[1] = true;
    for (int i = 2; i * i < N; ++i) {
        if (!p[i]) {
            for (int j = i * i; j < N; j += i) {
                p[j] = true;
            }
        }
    }
    for (int i = m; i <= n; ++i) {
        if (p[i]) {
            continue;
        }
        int x = i, y = 0;
        while (x) {
            y = y * 10 + x % 10;
            x /= 10;
        }
        if (!p[y]) {
            if (cnt) {
                cout << ",";
            }
            cout << i;
            ++cnt;
        }
    }
    if (!cnt) {
        cout << "No";
    }
    cout << "\n";
    return;
}

signed main() {
    input();
    solve();
    return 0;
}