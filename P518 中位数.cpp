#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int n, k, i, p, v, len;
long long ans;
int a[N];
long long cl[2][2 * N], cr[2][2 * N];

signed main() {
    scanf("%d %d", &n, &k);
    p = 0;
    for (i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        if (a[i] == k) {
            p = i;
        }
    }
    v = 0;
    len = 0;
    cl[0][N] = 1;
    for (i = p - 1; i >= 1; i--) {
        if (a[i] > k) {
            v++;
        } else {
            v--;
        }
        len++;
        cl[len & 1][v + N]++;
    }
    v = 0;
    len = 0;
    cr[0][N] = 1;
    for (i = p + 1; i <= n; i++) {
        if (a[i] > k) {
            v++;
        } else {
            v--;
        }
        len++;
        cr[len & 1][v + N]++;
    }
    ans = 0;
    for (int par = 0; par < 2; par++) {
        for (i = 0; i < 2 * N; i++) {
            if (cl[par][i] == 0) {
                continue;
            }
            int j = 2 * N - i;
            if (j < 0 || j >= 2 * N) {
                continue;
            }
            ans += cl[par][i] * cr[par][j];
        }
    }
    printf("%lld\n", ans);
    return 0;
}
