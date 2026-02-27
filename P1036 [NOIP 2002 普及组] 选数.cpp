#pragma G++ optimize("O3", "unroll-loops", "omit-frame-pointer", "inline")
#include <bits/stdc++.h>
using namespace std;
bool isprime(int a) {
    if (a == 1)
        return false;
    for (int i = 2; i * i <= a; i++)
        if (a % i == 0)
            return false;
    return true;
}
int n, k, a[25];
long long ans;
void dfs(int m, int sum, int startx) {
    if (m == k) {
        if (isprime(sum))
            ans++;
        return;
    }
    for (int i = startx; i < n; i++)
        dfs(m + 1, sum + a[i], i + 1);
    return;
}
int main() {
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    dfs(0, 0, 0);
    printf("%d\n", ans);
    return 0;
}
