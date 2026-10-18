#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 5;
int l, m, s;
bool t[N];

inline void input() {
    cin >> l >> m;
    return;
}

inline void solve() {
    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        for (int j = a; j <= b; j++) {
            if (!t[j]) {
                t[j] = true, s++;
            }
        }
    }
    cout << l + 1 - s << "\n";
    return;
}

signed main() {
    input();
    solve();
    return 0;
}