#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n, a[N], b[N], c[N];
long long s;

inline void input() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i], s += a[i];
    }
}

inline void solve() {
    sort(a + 1, a + n + 1);
    int m = 0;
    for (int i = n; i >= 1; i--) {
        if (m > 0 && a[i] == b[m]) {
            continue;
        }
        b[++m] = a[i];
    }
    cout << s << "\n"
         << b[1] << "\n"
         << b[m] << "\n";
    for (int i = 1; i <= m; i++) {
        cout << b[i] << (i == m ? "\n" : " ");
    }
    return;
}

signed main() {
    input(), solve();
    return 0;
}