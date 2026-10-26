#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
const int M = 2e5 + 5;

int n, k, i, p, v, len;
long long ans;
int a[N];
long long cl[2][M], cr[2][M];

signed main() {
    scanf("%d %d", &n, &k);
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
        for (i = 0; i < M; i++) {
            if (cl[par][i] > 0 && cr[par][M - 1 - i] > 0) {
                ans += cl[par][i] * cr[par][M - 1 - i];
            }
        }
    }
    printf("%lld\n", ans);
    return 0;
}
