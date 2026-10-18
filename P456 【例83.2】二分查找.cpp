#include <bits/stdc++.h>
using namespace std;

const int N = 3e4 + 5;
int n, a[N], t;

signed main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    cin >> t;
    for (int i = 1; i <= t; i++) {
        int key, l = 1, r = n;
        cin >> key;
        for (; l < r;) {
            int m = (l + r) >> 1;
            if (a[m] >= key) {
                r = m;
            } else {
                l = m + 1;
            }
        }
        if (i > 1) {
            cout << " ";
        }
        cout << (l <= n && a[l] == key ? l : -1);
    }
    cout << "\n";
    return 0;
}
