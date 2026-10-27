#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 5;
long long a[N];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    for (; t; t--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        bool z = true;
        for (int i = 2; i <= n; i++) {
            if (a[i] != a[i - 1]) {
                z = false;
            }
        }
        if (z) {
            cout << 1 << "\n";
            continue;
        }
        int blk = 1, sg = 0;
        for (int i = 2; i <= n; i++) {
            long long d = a[i] - a[i - 1];
            int s = 0;
            if (d > 0) {
                s = 1;
            } else if (d < 0) {
                s = -1;
            }
            if (s == 0) {
                continue;
            }
            if (sg == 0) {
                sg = s;
            } else if (sg != s) {
                blk++;
                sg = s;
            }
        }
        cout << blk + 1 << "\n";
    }
    return 0;
}
