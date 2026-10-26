#include <bits/stdc++.h>
using namespace std;

int n, a[100005];
long long s[100005];

signed main() {
    int t, i;
    long long x;
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    for (; t; t--) {
        cin >> n;
        for (i = 1; i <= n; i++) {
            cin >> x;
            if (i % 2 == 1) {
                a[i] = 1;
            } else {
                a[i] = -1;
            }
            s[i] = s[i - 1] + x * a[i];
        }
        sort(s, s + n + 1);
        int f = 0;
        for (i = 1; i <= n; i++) {
            if (s[i] == s[i - 1]) {
                f = 1;
            }
        }
        if (f) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
    return 0;
}
