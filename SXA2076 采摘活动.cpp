#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int n, i, mx, mn, cnt;
long long s;
int a[N];

signed main() {
    scanf("%d", &n);
    for (i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    mx = a[1];
    mn = a[1];
    for (i = 2; i <= n; i++) {
        if (a[i] > mx) {
            mx = a[i];
        }
        if (a[i] < mn) {
            mn = a[i];
        }
    }
    for (i = 1; i <= n; i++) {
        if (a[i] != mx && a[i] != mn) {
            s += a[i];
            cnt++;
        }
    }
    printf("%lld\n", s);
    if (cnt > 0) {
        printf("%.1f\n", (double)s / cnt);
    } else {
        printf("0.0\n");
    }
    return 0;
}
