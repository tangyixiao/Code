#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 5, M = 1e5 + 5;
int a[N], t[M];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    long long ans = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        int p = a[i] + 1;
        for (; p < M; p += p & -p) {
            t[p]++;
        }
        int s = 0;
        for (p = a[i]; p > 0; p -= p & -p) {
            s += t[p];
        }
        ans += i - 1 - s;
    }
    cout << ans << "\n";
    return 0;
}
