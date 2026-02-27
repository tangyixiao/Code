#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5 + 5;
int n, k, a[N];
int b[N];
bool check(int mid) {
    for (int i = 1; i <= n; i++) {
        b[i] = b[i - 1] + a[i] - mid;
    }
    int res = -1, mnv = 1e9;
    for (int i = k; i <= n; i++) {
        mnv = min(mnv, b[i - k]);
        res = max(res, b[i] - mnv);
    }
    return res >= 0;
}
main() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] *= 10000;
    }
    int l = 1, r = 2e7;
    while (l < r) {
        int mid = (l + r) >> 1;
        if (check(mid)) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    if (!check(l)) {
        l--;
    }
    cout << l / 10;
    return 0;
}
