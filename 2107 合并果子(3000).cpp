#include <bits/stdc++.h>
using namespace std;

const int N = 3e3 + 5;
int n, a[N], b[N];

inline void input() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        b[i] = a[i];
    }
}

inline void solve() {
    sort(b + 1, b + n + 1);
    int m = n;
    long long ans = 0;
    while (m > 1) {
        int s = b[1] + b[2];
        ans += s;
        for (int i = 1; i <= m - 2; ++i) {
            b[i] = b[i + 2];
        }
        --m;
        int j = m;
        while (j > 1 && b[j - 1] > s) {
            b[j] = b[j - 1];
            --j;
        }
        b[j] = s;
    }
    cout << ans << "\n";
    return;
}

signed main() {
    input();
    solve();
    return 0;
}
