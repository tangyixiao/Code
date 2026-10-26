#include <bits/stdc++.h>
using namespace std;
const int N = 1e2 + 5;
int n, x, i, cnt, a[N];
signed main() {
    cin >> n;
    for (i = 1; i <= n; i++) {
        cin >> a[i];
    }
    cin >> x;
    cnt = 0;
    for (i = 1; i <= n; i++) {
        if (a[i] > x) {
            cnt++;
        }
    }
    cout << cnt + 1 << "\n";
    return 0;
}
