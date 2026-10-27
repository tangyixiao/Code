#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int n, a[N], c[N];
long long ans;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = n; i >= 1; i--) {
        for (int j = a[i] - 1; j >= 1; j -= j & -j) {
            ans += c[j];
        }
        for (int j = a[i]; j < N; j += j & -j) {
            c[j]++;
        }
    }
    cout << ans << "\n";
    return 0;
}
