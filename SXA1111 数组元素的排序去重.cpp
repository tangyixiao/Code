#include <bits/stdc++.h>
using namespace std;

int a[10005];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);
    int m = unique(a, a + n) - a;
    for (int i = 0; i < m; i++) {
        cout << a[i];
        if (i + 1 < m) {
            cout << ' ';
        }
    }
    cout << "\n";
    return 0;
}
