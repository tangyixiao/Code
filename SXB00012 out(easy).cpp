#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
const int INF = 1e9;

int n, m, seed1, seed2, cntneg, z;
int x[N], suf[N];
int st[N];

signed main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &x[i]);
    }
    suf[n + 1] = INF;
    for (int i = n; i >= 1; i--) {
        suf[i] = min(suf[i + 1], x[i]);
    }
    int nxt = 1, top = 0, first = 1;
    while (nxt <= n || top > 0) {
        if (top > 0 && (nxt > n || st[top] < suf[nxt])) {
            if (!first) {
                printf(" ");
            }
            printf("%d", st[top]);
            first = 0;
            top--;
        } else {
            st[++top] = x[nxt];
            nxt++;
        }
    }
    printf("\n");
    return 0;
}
