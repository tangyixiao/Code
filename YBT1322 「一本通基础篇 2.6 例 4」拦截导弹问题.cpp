#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;

int n;
int a[N], f[N];

inline void input() {
    cin >> n;
}

inline void solve() {
    int k = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        int j = 0;
        for (; j < k; ++j) {
            if (f[j] >= a[i]) {
                break;
            }
        }
        for (int t = k; t > j; --t) {
            f[t] = f[t - 1];
        }
        f[j] = a[i];
        if (j == k) {
            ++k;
        }
    }
    cout << k << "\n";
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    input();
    solve();
    return 0;
}
