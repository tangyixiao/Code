#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
long long n, s[N], m;

signed main() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> s[i];
    }
    if (n <= m) {
        cout << n << "\n";
        return 0;
    }
    long long r = n - m;
    long long lo = 1, hi = 0;
    long long mx = 0;
    for (int i = 1; i <= m; i++) {
        mx = max(mx, s[i]);
    }
    hi = mx * r;
    for (; lo < hi;) {
        long long mid = (lo + hi) / 2, c = 0;
        for (int i = 1; i <= m; i++) {
            c += mid / s[i];
            if (c > r) {
                break;
            }
        }
        if (c >= r) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }
    long long v = lo, prev = 0, off = 0;
    for (int i = 1; i <= m; i++) {
        prev += (v - 1) / s[i];
    }
    off = r - prev;
    for (int i = 1; i <= m; i++) {
        if (v % s[i] == 0) {
            if (off == 1) {
                cout << i << "\n";
                return 0;
            }
            off--;
        }
    }
    return 0;
}
