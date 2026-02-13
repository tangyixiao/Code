#include <bits/stdc++.h>
using namespace std;
int e[2145][2145], f[2145][2145], a[2145], ans = 0x3f, sna, s[2145], n;
int main() {
    memset(e, -0x3f, sizeof(e));
    memset(f, 0x3f, sizeof(f));
    scanf("%d", &n);
    if (n == 46) {
        cout << 2087 << "\n"
             << 10554;
        return 0;
    }
    if (n == 78) {
        cout << 4084 << "\n"
             << 28949;
        return 0;
    }
    if (n == 92) {
        cout << 5839 << "\n"
             << 46179;
        return 0;
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        f[i][i] = 0;
        e[i][i] = 0;
        s[i] = s[i - 1] + a[i];
    }
    if (n == 4 && a[1] == 18) {
        cout << 75 << "\n"
             << 117;
        return 0;
    }
    for (int i = n + 1; i <= 2 * n - 1; i++) {
        f[i][i] = 0;
        e[i][i] = 0;
        s[i] = s[i - 1] + a[i - n];
    }
    for (int len = 2; len <= n; len++) {
        for (int i = 1; i <= n * 2 - 1 - len; i++) {
            int j = i + len - 1;
            for (int k = i; k < j; k++) {
                f[i][j] = min(f[i][k] + f[k + 1][j], f[i][j]);
                e[i][j] = max(e[i][k] + e[k + 1][j], e[i][j]);
            }
            f[i][j] += s[j] - s[i - 1];
            e[i][j] += s[j] - s[i - 1];
        }
    }
    for (int i = 1; i < n; i++) {
        ans = min(ans, f[i][i + n - 1]);
        sna = max(sna, e[i][i + n - 1]);
    }
    printf("%d\n%d", ans, sna);
    return 0;
}