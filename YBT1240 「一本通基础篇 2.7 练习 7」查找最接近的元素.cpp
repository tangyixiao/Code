#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int a[N], n, m;
long long x;

signed main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> x;
        int l = 0, r = n - 1;
        for (; l < r;) {
            int md = (l + r) / 2;
            if (a[md] < x) {
                l = md + 1;
            } else {
                r = md;
            }
        }
        if (l == 0) {
            cout << a[0] << "\n";
        } else if (l == n) {
            cout << a[n - 1] << "\n";
        } else {
            cout << (x - a[l - 1] <= a[l] - x ? a[l - 1] : a[l]) << "\n";
        }
    }
    return 0;
}
