#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int n, p[N], ans;

signed main() {
    cin >> n;
    for (int i = 2; i <= n; i++) {
        p[i] = 1;
    }
    for (int i = 2; i * i <= n; i++) {
        if (p[i]) {
            for (int j = i * i; j <= n; j += i) {
                p[j] = 0;
            }
        }
    }
    for (int i = 2; i + 2 <= n; i++) {
        if (i >= 2 && i <= n - 2 && p[i] && p[i + 2]) {
            ans++;
        }
    }
    cout << ans << "\n";
    return 0;
}
