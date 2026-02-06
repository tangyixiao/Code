// SPJ
#include <bits/stdc++.h>
using namespace std;
const int N = 2e3 + 5;
int T, n, r[N], c[N];
signed main() {
    for (cin >> T; T--;) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> r[i];
        }
        for (int i = 1; i <= n; i++) {
            cin >> c[i];
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                cout << min(r[i], c[j]) - 1 << ' ';
            }
            cout << '\n';
        }
    }
    return 0;
}