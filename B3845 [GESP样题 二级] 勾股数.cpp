#include <bits/stdc++.h>
using namespace std;
int n, ans;
signed main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            for (int k = j + 1; k <= n; k++) {
                if (i * i + j * j == k * k) {
                    ans++;
                }
            }
        }
    }
    cout << ans;
    return 0;
}