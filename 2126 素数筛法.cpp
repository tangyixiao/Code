#include <bits/stdc++.h>
using namespace std;

const int N = 1e7 + 5;
int n;
bool p[N];

inline void input() {
    cin >> n;
}

inline void solve() {
    int cnt = 0;
    for (int i = 2; i <= n; ++i) {
        if (p[i]) {
            continue;
        }
        ++cnt;
        for (int j = i + i; j <= n; j += i) {
            p[j] = true;
        }
    }
    cout << cnt << "\n";
    return;
}

signed main() {
    input();
    solve();
    return 0;
}
