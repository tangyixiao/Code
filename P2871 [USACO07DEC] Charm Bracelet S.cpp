#include <bits/stdc++.h>
using namespace std;
struct node {
    int t, p;
} a[3403];
int l, m, dp[12881];
int main() {
    scanf("%d%d", &m, &l);
    for (int i = 1; i <= m; i++) {
        scanf("%d %d", &a[i].t, &a[i].p);
    }
    for (int i = 1; i <= m; i++) {
        for (int j = l; j >= 0; j--) {
            if (j >= a[i].t) {
                dp[j] = max(dp[j - a[i].t] + a[i].p, dp[j]);
            }
        }
    }
    printf("%d", dp[l]);
    return 0;
}