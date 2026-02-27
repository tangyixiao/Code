#include <bits/stdc++.h>
#define int long long
int n, pd;
bool q(int x) {
    if (x == 1)
        return 0;
    for (int i = 2; i * i <= x; i++)
        if (x % i == 0)
            return 0;
    return 1;
}
void solve(int x) {
    for (int i = 2; x > 1 && i <= x; i++) {
        if (x % i == 0) {
            int cnt = 0;
            while (x % i == 0)
                x /= i, cnt++;
            if (pd) {
                printf("* ");
            } else
                pd = 1;
            if (cnt > 1)
                printf("%lld^%lld ", i, cnt);
            else
                printf("%lld ", i);
            if (q(x)) {
                printf("* %lld", x);
                return;
            }
        }
    }
}
signed main() {
    scanf("%lld", &n);
    if (q(n)) {
        printf("%lld", n);
        return 0;
    }
    solve(n);
    return 0;
}
