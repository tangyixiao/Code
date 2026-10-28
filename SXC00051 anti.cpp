#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
int n, i, l, r, k, m;
long long ans;
char s[N];
int v[N], d2[N];
signed main() {
    scanf("%d", &n);
    scanf("%s", s);
    for (i = 0; i < n; i++) {
        v[i] = (s[i] - '0') ^ (i & 1);
    }
    m = n;
    l = 0;
    r = -1;
    ans = 0;
    for (i = 0; i < m; i++) {
        k = (i > r) ? 0 : min(d2[l + r - i + 1], r - i + 1);
        while (i - k - 1 >= 0 && i + k < m && v[i - k - 1] == v[i + k]) {
            k++;
        }
        d2[i] = k;
        if (i + k - 1 > r) {
            l = i - k;
            r = i + k - 1;
        }
        ans += k;
    }
    printf("%lld\n", ans);
    return 0;
}
