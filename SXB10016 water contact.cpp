#include <bits/stdc++.h>
using namespace std;

const int N = 1005;

int n, i;
long long s;
int a[N];

signed main() {
    scanf("%d", &n);
    for (i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    sort(a + 1, a + n + 1);
    for (i = 1; i <= n; i++) {
        s += 1LL * (n - i + 1) * a[i];
    }
    printf("%.2f\n", (double)s / n);
    return 0;
}
