#include <bits/stdc++.h>
using namespace std;

const int N = 2e6 + 5;
int cnt[N];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, x, mx = 0;
    long long ans = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x;
        cnt[x]++;
        mx = max(mx, x);
    }
    for (int i = 0; i <= mx + 40; i++) {
        if (cnt[i] == 0) {
            if (i > mx) {
                break;
            }
            ans++;
            continue;
        }
        int m = cnt[i] - 1;
        if (m % 2 == 1) {
            ans++;
            m++;
        }
        cnt[i + 1] += m / 2;
    }
    cout << ans << "\n";
    return 0;
}
