#include <bits/stdc++.h>
using namespace std;

const int N = 1005;

int n, i, j, tot;
int t[N], w[N], idx[N], dp[N];

bool cmp(int a, int b) {
    return t[a] < t[b];
}

signed main() {
    scanf("%d", &n);
    for (i = 1; i <= n; i++) {
        scanf("%d", &t[i]);
    }
    for (i = 1; i <= n; i++) {
        scanf("%d", &w[i]);
        tot += w[i];
        idx[i] = i;
    }
    sort(idx + 1, idx + n + 1, cmp);
    for (i = 1; i <= n; i++) {
        dp[i] = -1e9;
    }
    dp[0] = 0;
    int mx = 0;
    for (i = 1; i <= n; i++) {
        int id = idx[i];
        int up = t[id];
        if (up > n) {
            up = n;
        }
        for (j = up; j >= 1; j--) {
            if (dp[j - 1] + w[id] > dp[j]) {
                dp[j] = dp[j - 1] + w[id];
            }
            if (j > mx && dp[j] > -1e8) {
                mx = j;
            }
        }
    }
    int best = 0;
    for (i = 0; i <= n; i++) {
        if (dp[i] > best) {
            best = dp[i];
        }
    }
    printf("%d\n", tot - best);
    return 0;
}
