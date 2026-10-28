#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
const int V = 1e2 + 5;
int a[N], st[N], cnt[V];
int n, m, p, re, top, i, mn, out[N];
signed main() {
    scanf("%d%d", &n, &m);
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    p = 0, re = min(n - 1, m - 1), top = 0;
    for (i = p; i <= re; i++) {
        cnt[a[i]]++;
    }
    i = 0;
    while (i < n) {
        mn = 1;
        while (mn <= 100 && cnt[mn] == 0) {
            mn++;
        }
        if (top > 0 && st[top] <= mn) {
            out[i++] = st[top--];
            if (re + 1 <= n - 1) {
                re++;
                cnt[a[re]]++;
            }
        } else {
            cnt[a[p]]--;
            st[++top] = a[p];
            p++;
        }
    }
    for (i = 0; i < n; i++) {
        if (i) {
            printf(" ");
        }
        printf("%d", out[i]);
    }
    printf("\n");
    return 0;
}
