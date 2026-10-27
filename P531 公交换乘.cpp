#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int n, tp, p, t, qt[N], qp[N], hd = 1, tl = 0;
long long ans;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> tp >> p >> t;
        while (hd <= tl && t - qt[hd] > 45) {
            hd++;
        }
        if (tp == 0) {
            ans += p;
            tl++;
            qt[tl] = t;
            qp[tl] = p;
        } else {
            int k = 0;
            for (int j = hd; j <= tl; j++) {
                if (qp[j] >= p) {
                    k = j;
                    break;
                }
            }
            if (k) {
                qp[k] = 0;
            } else {
                ans += p;
            }
        }
    }
    cout << ans << "\n";
    return 0;
}
