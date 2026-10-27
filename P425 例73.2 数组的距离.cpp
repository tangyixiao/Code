#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int a[N], b[N], n, m, i, j, ans;
signed main() {
    scanf("%d%d", &n, &m);
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    for (i = 0; i < m; i++) {
        scanf("%d", &b[i]);
    }
    sort(a, a + n), sort(b, b + m);
    i = 0, j = 0, ans = 2000000005;
    while (i < n && j < m) {
        int d = a[i] - b[j];
        if (d < 0) {
            d = -d;
        }
        if (d < ans) {
            ans = d;
        }
        if (a[i] < b[j]) {
            i++;
        } else {
            j++;
        }
    }
    printf("%d\n", ans);
    return 0;
}
