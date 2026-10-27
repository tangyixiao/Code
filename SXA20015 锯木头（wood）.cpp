#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int n, i;
long long k, mx, lo, hi, mid, ans, c;
long long a[N];

long long cv(string s) {
    long long ip = 0, fp = 0;
    int p = 0, m = s.size(), f = 0;
    for (; p < m && s[p] != '.'; p++) {
        ip = ip * 10 + (s[p] - '0');
    }
    if (p < m) {
        p++;
    }
    for (; p < m && f < 2; p++, f++) {
        fp = fp * 10 + (s[p] - '0');
    }
    for (; f < 2; f++) {
        fp *= 10;
    }
    return ip * 100 + fp;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> n >> k;
    mx = 0;
    for (i = 1; i <= n; i++) {
        cin >> s;
        a[i] = cv(s);
        if (a[i] > mx) {
            mx = a[i];
        }
    }
    lo = 1, hi = mx, ans = 0;
    for (; lo <= hi;) {
        mid = (lo + hi) / 2;
        c = 0;
        for (i = 1; i <= n; i++) {
            c += a[i] / mid;
            if (c >= k) {
                break;
            }
        }
        if (c >= k) {
            ans = mid, lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }
    cout << ans / 100 << ".";
    long long r = ans % 100;
    if (r < 10) {
        cout << "0";
    }
    cout << r << "\n";
    return 0;
}
