#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
int n, c[N], d[N];
long long best = -1;
int bk;

signed main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> c[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> d[i];
    }
    for (int k = 1; k <= n; k++) {
        long long val[N];
        for (int i = 1; i <= n; i++) {
            val[i] = c[i] - (long long)(k - 1) * d[i];
        }
        sort(val + 1, val + n + 1, greater<long long>());
        long long s = 0;
        for (int i = 1; i <= k; i++) {
            s += val[i];
        }
        if (s >= best) {
            best = s;
            bk = k;
        }
    }
    cout << best << "\n"
         << bk << "\n";
    return 0;
}
