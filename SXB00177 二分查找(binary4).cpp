#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
int n, x, a[N];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cin >> x;
    int l = 0, r = n, pos = -1;
    for (; l < r;) {
        int mid = (l + r) / 2;
        if (a[mid] == x) {
            pos = mid;
            break;
        } else if (a[mid] < x) {
            l = mid + 1;
        } else {
            r = mid;
        }
    }
    if (pos >= 0) {
        cout << pos + 1 << "\n";
    } else {
        cout << -1 << "\n";
    }
    return 0;
}
