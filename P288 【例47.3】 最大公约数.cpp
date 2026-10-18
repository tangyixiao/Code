#include <bits/stdc++.h>
using namespace std;

int n;

inline void input() {
    cin >> n;
}

inline void solve() {
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        for (; b;) {
            int t = a % b;
            a = b, b = t;
        }
        cout << a << "\n";
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
