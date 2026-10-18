#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int n;
bool p[N];

inline void input() { cin >> n; }

inline void solve() {
    p[0] = p[1] = true;
    for (int i = 2; i * i <= n; ++i) {
        if (!p[i]) {
            for (int j = i * i; j <= n; j += i) {
                p[j] = true;
            }
        }
    }
    int cnt = 0;
    for (int i = 2; i + 2 <= n; ++i) {
        if (!p[i] && !p[i + 2]) {
            cout << i << " " << i + 2 << "\n";
            ++cnt;
        }
    }
    if (!cnt) {
        cout << "empty\n";
    }
    return;
}

signed main() {
    input();
    solve();
    return 0;
}