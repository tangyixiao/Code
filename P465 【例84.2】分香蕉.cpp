#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int n, m, a[N], b[N];
long long s[N];

signed main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= m; i++) {
        cin >> b[i];
    }
    sort(a + 1, a + n + 1, greater<int>());
    for (int i = 0; i < n; i++) {
        s[i % m + 1] += a[i + 1];
    }
    sort(b + 1, b + m + 1, greater<int>());
    for (int i = 1; i <= m; i++) {
        if (i > 1) {
            cout << " ";
        }
        cout << s[i];
    }
    cout << "\n";
    return 0;
}
