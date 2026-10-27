#include <bits/stdc++.h>
using namespace std;

const int N = 1e2 + 5;
const int P = 1e9 + 7;
int n, m[N];

signed main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &m[i]);
    }
    sort(m + 1, m + n + 1);
    long long ans = 1;
    for (int i = 1; i <= n; i++) {
        long long f = m[i] - i + 1;
        if (f <= 0) {
            ans = 0;
            break;
        }
        ans = ans * f % P;
    }
    printf("%lld\n", ans);
    return 0;
}
