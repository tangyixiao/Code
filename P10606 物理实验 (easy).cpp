#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    vector<long long> a(n + 1);
    for (int i = 1; i <= n; ++i)
        scanf("%lld", &a[i]);

    int max_x = 0;
    for (int i = 0; i < m; ++i) {
        int x, y;
        scanf("%d%d", &x, &y);
        if (x > max_x)
            max_x = x;
    }

    if (max_x == 0) {
        printf("0\n");
        return 0;
    }

    long long ans = 1e18;
    for (int i = max_x; i <= n; ++i) {
        if (a[i] < ans)
            ans = a[i];
    }
    printf("%lld\n", ans);
    return 0;
}