#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int n, m, i, j;
int a[N], b[N], idx[N];
long long s[N];

bool cmp(int x, int y) {
    return b[x] > b[y];
}

signed main() {
    scanf("%d %d", &n, &m);
    for (i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    for (i = 1; i <= m; i++) {
        scanf("%d", &b[i]);
    }
    sort(a + 1, a + n + 1, greater<int>());
    for (i = 1; i <= m; i++) {
        idx[i] = i;
    }
    sort(idx + 1, idx + m + 1, cmp);
    for (i = 0; i < n; i++) {
        j = i % m;
        s[idx[j + 1]] += a[i + 1];
    }
    for (i = 1; i <= m; i++) {
        if (i > 1) {
            printf(" ");
        }
        printf("%lld", s[i]);
    }
    printf("\n");
    return 0;
}
