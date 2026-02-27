#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int n, x, a[N], l, r, mid;
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    cin >> x;
    l = 1, r = n;
    while (l <= r) {
        mid = (l + r) >> 1;
        if (a[mid] == x) {
            cout << mid;
            exit(0);
        } else {
            if (a[mid] > x) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
    }
    cout << "-1";
    return 0;
}