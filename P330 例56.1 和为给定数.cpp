#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n, m, i, p, need, a[N];
signed main() {
    cin >> n;
    for (i = 0; i < n; i++) {
        cin >> a[i];
    }
    cin >> m;
    sort(a, a + n);
    for (i = 0; i < n; i++) {
        need = m - a[i];
        p = lower_bound(a + i + 1, a + n, need) - a;
        if (p < n && a[p] == need) {
            cout << a[i] << " " << need << "\n";
            return 0;
        }
    }
    cout << "No\n";
    return 0;
}
