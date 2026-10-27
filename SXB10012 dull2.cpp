#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
long long h[N], v[N], s[N];
int st[N], n, i, top;
long long ans;
signed main() {
    scanf("%d", &n);
    for (i = 1; i <= n; i++) {
        scanf("%lld%lld", &h[i], &v[i]);
    }
    top = 0;
    for (i = 1; i <= n; i++) {
        while (top > 0 && h[st[top]] <= h[i]) {
            top--;
        }
        if (top > 0) {
            s[st[top]] += v[i];
        }
        st[++top] = i;
    }
    top = 0;
    for (i = n; i >= 1; i--) {
        while (top > 0 && h[st[top]] <= h[i]) {
            top--;
        }
        if (top > 0) {
            s[st[top]] += v[i];
        }
        st[++top] = i;
    }
    ans = 0;
    for (i = 1; i <= n; i++) {
        if (s[i] > ans) {
            ans = s[i];
        }
    }
    printf("%lld\n", ans);
    return 0;
}
