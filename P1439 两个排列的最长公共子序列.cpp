#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n, a[N], ans, x, k, c[N], b[N], LCS[N], l, r, mid;
int found(int x) {
    l = 0, r = ans;
    while (l < r) {
        mid = (l + r) / 2 + 1;
        if (LCS[mid] >= x) {
            r = mid - 1;
        }

        else {
            l = mid;
        }
    }
    return l;
}
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        c[a[i]] = i;
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d", &x);
        b[i] = c[x];
    }
    for (int i = 1; i <= n; i++) {
        k = found(b[i]) + 1;
        ans = max(ans, k);
        LCS[k] = (!LCS[k] ? b[i] : min(LCS[k], b[i]));
    }
    printf("%d", ans);
    return 0;
}
