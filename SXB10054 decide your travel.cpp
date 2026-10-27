#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 5;
int t, n, jd;
int a[N];

signed main() {
    cin >> t;
    for (int cas = 1; cas <= t; cas++) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        jd = -1;
        for (int i = n; i >= 1; i--) {
            if (a[i] == 0 && (i == n || a[i + 1] == 1)) {
                jd = i;
                break;
            }
        }
        if (jd == n) {
            for (int i = 1; i <= n; i++) {
                cout << i << " ";
            }
            cout << n + 1 << "\n";
        } else if (jd > 0) {
            for (int i = 1; i <= jd; i++) {
                cout << i << " ";
            }
            cout << n + 1;
            for (int i = jd + 1; i <= n; i++) {
                cout << " " << i;
            }
            cout << "\n";
        } else if (a[1] == 1) {
            cout << n + 1;
            for (int i = 1; i <= n; i++) {
                cout << " " << i;
            }
            cout << "\n";
        } else {
            cout << -1 << "\n";
        }
    }
    return 0;
}
