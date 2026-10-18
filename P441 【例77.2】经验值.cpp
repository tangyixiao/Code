#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int n, p[N], ls[N], rs[N];
long long ans;

signed main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
    }
    for (int i = 1; i <= n; i++) {
        ls[i] = i - 1, rs[i] = i + 1;
    }
    ls[1] = 0, rs[n] = 0;
    for (int i = 1; i <= n; i++) {
        int d;
        cin >> d;
        if (ls[d]) {
            rs[ls[d]] = rs[d];
        }
        if (rs[d]) {
            ls[rs[d]] = ls[d];
        }
        ans += p[ls[d]] + p[rs[d]];
    }
    cout << ans << "\n";
    return 0;
}
