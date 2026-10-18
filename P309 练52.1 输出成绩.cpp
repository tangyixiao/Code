#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;

int n, a[N];
double s;

inline void input() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i], s += a[i];
    }
}

inline void solve() {
    s /= n;
    cout << fixed << setprecision(3) << s << "\n";
    for (int i = 1; i <= n; i++) {
        if (a[i] > s) {
            cout << a[i] << "\n";
        }
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
