#pragma G++ optimize("O3", "unroll-loops", "omit-frame-pointer", "inline")
#include <bits/stdc++.h>
#define int long long
const int mod = 998244353;
using namespace std;
long double dp[500201];
long long L, P, n, ans[500021], a[500201], sum[500201], dl[500201], hd, ta;
inline long double fast_pow(long double a, int b) {
    long double t = 1;
    while (b) {
        if (b & 1LL)
            t = t * a;
        b >>= 1LL;
        a = a * a;
    }
    return t;
}
inline long double calc(int i, int x) {
    return dp[i] + fast_pow(abs(sum[x] - sum[i] + x - i - 1 - L), P);
}
inline int get(int a, int b) {
    if (calc(a, n) < calc(b, n))
        return n + 1;
    int lb = b, rb = n, ans = -1;
    while (lb <= rb) {
        int mid = (lb + rb) >> 1;
        if (calc(b, mid) <= calc(a, mid))
            ans = mid, rb = mid - 1;
        else
            lb = mid + 1;
    }
    return ans;
}
int sta[100202], T;
char s[102002][32];
signed main() {
    ios::sync_with_stdio(0);
    cin >> T;
    while (T--) {
        cin >> n >> L >> P;
        for (int i = 1; i <= n; i++) {
            cin >> s[i];
            a[i] = strlen(s[i]);
            sum[i] = sum[i - 1] + a[i];
            ans[i] = 0;
            dp[i] = 1e19;
        }
        hd = 1, ta = 1;
        for (int i = 1; i <= n; i++) {
            while (hd < ta && get(dl[hd], dl[hd + 1]) <= i)
                hd++;
            ans[i] = dl[hd];
            dp[i] = calc(dl[hd], i);
            while (hd < ta && get(dl[ta - 1], dl[ta]) >= get(dl[ta], i))
                ta--;
            dl[++ta] = i;
        }
        if (dp[n] > 1e18) {
            puts("Too hard to arrange");
        } else {
            printf("%lld\n", (long long)dp[n]);
            int top = 0;
            for (int tmp = n; tmp; tmp = ans[tmp])
                sta[++top] = tmp;
            sta[++top] = 0;
            for (int i = top; i > 1; i--) {
                for (int j = sta[i] + 1; j < sta[i - 1]; j++) {
                    printf("%s ", s[j]);
                }
                printf("%s", s[sta[i - 1]]);
                printf("\n");
            }
        }
        puts("--------------------");
    }
    return 0;
}
