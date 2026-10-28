#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
char s[N];
long long len[N], n, k, i, l, r, mid, cnt, mx, ans;
signed main() {
    scanf("%lld%lld", &n, &k);
    for (i = 0; i < n; i++) {
        scanf("%s", s);
        long long ip = 0, fp = 0, fl = 0, t;
        for (t = 0; s[t] && s[t] != '.'; t++) {
            ip = ip * 10 + s[t] - '0';
        }
        if (s[t] == '.') {
            for (t++; s[t] && fl < 2; t++, fl++) {
                fp = fp * 10 + s[t] - '0';
            }
        }
        while (fl < 2) {
            fp *= 10, fl++;
        }
        len[i] = ip * 100 + fp;
        if (len[i] > mx) {
            mx = len[i];
        }
    }
    l = 1, r = mx, ans = 0;
    for (; l <= r;) {
        mid = (l + r) / 2, cnt = 0;
        for (i = 0; i < n; i++) {
            cnt += len[i] / mid;
        }
        if (cnt >= k) {
            ans = mid, l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    printf("%lld.%02lld\n", ans / 100, ans % 100);
    return 0;
}
