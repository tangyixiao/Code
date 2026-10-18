#include <bits/stdc++.h>
using namespace std;

const int N = 3e2 + 5;
int n;
double a[N];

inline void input() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
}

inline void solve() {
    sort(a + 1, a + n + 1);
    double s = 0;
    for (int i = 2; i <= n - 1; ++i) {
        s += a[i];
    }
    double p = s / (n - 2), e = 0;
    for (int i = 2; i <= n - 1; ++i) {
        e = max(e, fabs(a[i] - p));
    }
    cout << fixed << setprecision(2) << p << " " << e << "\n";
    return;
}

signed main() {
    input();
    solve();
    return 0;
}