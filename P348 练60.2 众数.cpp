#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n, a[N], b[N];

inline void input() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
}

inline void solve() {
    sort(a + 1, a + n + 1);
    int mx = 0, r = 0, c = 0;
    for (int i = 1; i <= n; i++) {
        if (i > 1 && a[i] == a[i - 1]) {
            c++;
        } else {
            c = 1;
        }
        if (c > mx) {
            mx = c, r = a[i];
        }
    }
    cout << r << "\n";
    return;
}

signed main() {
    input(), solve();
    return 0;
}