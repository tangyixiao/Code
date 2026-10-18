#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
int a[N], b[N], n;
long long s;

inline void input() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }
    return;
}

inline void solve() {
    for (int i = 1; i <= n; i++) {
        s += 1LL * a[i] * b[i];
    }
    cout << s << "\n";
    return;
}

signed main() {
    input();
    solve();
    return 0;
}