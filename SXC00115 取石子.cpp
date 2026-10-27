#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int n;
long long a[N], m1, m2, ans, c;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    m1 = -1;
    m2 = -1;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] > m1) {
            m2 = m1;
            m1 = a[i];
        } else if (a[i] > m2) {
            m2 = a[i];
        }
    }
    ans = (long long)(n - 1) * m1;
    if (n >= 3) {
        c = (long long)(n - 2) * (m1 + m2);
        if (c > ans) {
            ans = c;
        }
    }
    cout << ans << "\n";
    return 0;
}
