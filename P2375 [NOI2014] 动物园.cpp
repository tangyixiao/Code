#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 1e9 + 7, N = 1e6 + 10;
int T, n, fail[N], ans[N], cnt;
string a;
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> T;
    while (T--) {
        cin >> a;
        n = a.size();
        a = " " + a;
        cnt = 1;
        ans[1] = 1;
        for (int i = 2, j = 0; i <= n; i++) {
            while (j && (a[i] != a[j + 1])) {
                j = fail[j];
            }
            j += (a[i] == a[j + 1]);
            fail[i] = j;
            ans[i] = ans[j] + 1;
        }
        for (int i = 2, j = 0; i <= n; i++) {
            while (j && (a[i] != a[j + 1])) {
                j = fail[j];
            }
            j += (a[i] == a[j + 1]);
            while ((j << 1) > i) {
                j = fail[j];
            }
            cnt = (cnt * (ans[j] + 1)) % mod;
        }
        cout << cnt << "\n";
    }
    return 0;
}
