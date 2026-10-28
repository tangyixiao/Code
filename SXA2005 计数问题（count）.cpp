#include <bits/stdc++.h>
using namespace std;
int n, x, i, cnt;
signed main() {
    cin >> n >> x;
    for (i = 1; i <= n; i++) {
        int t = i;
        while (t) {
            if (t % 10 == x) {
                cnt++;
            }
            t /= 10;
        }
    }
    cout << cnt << "\n";
    return 0;
}
