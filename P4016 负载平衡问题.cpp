#include <algorithm>
#include <cstdio>
#include <cstdlib>

int a[105], s[105];
int main() {
    int n, sum = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
        sum += a[i];
    }
    int avg = sum / n;
    for (int i = 1; i <= n; ++i) {
        int c = a[i] - avg;
        s[i] = s[i - 1] + c;
    }
    std::sort(s + 1, s + n + 1);
    int med = s[(n + 1) / 2];
    long long ans = 0;
    for (int i = 1; i <= n; ++i)
        ans += abs(s[i] - med);
    printf("%lld\n", ans);
    return 0;
}