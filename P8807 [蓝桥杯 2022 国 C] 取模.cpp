#include <bits/stdc++.h>
using namespace std;
int t, n, m;
inline void solve() {
    cin >> n >> m;
    if (m > n + 1) {
        printf("Yes\n");
    } else {
        for (int i = 1; i <= m; i++) {
            if (n % i != i - 1) {
                printf("Yes\n");
                return;
            }
        }
        printf("No\n");
    }
    return;
}
int main() {
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
