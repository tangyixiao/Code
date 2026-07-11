#include <bits/stdc++.h>
using namespace std;
const int N = 2e7 + 5;
char s[N], t[N];
int n, m, z[N], p[N];
int main() {
    scanf("%s%s", t + 1, s + 1);
    m = strlen(t + 1), n = strlen(s + 1);
    z[1] = n;
    for (int i = 2, l = 0, r = 0; i <= n; i++) {
        z[i] = i > r ? 0 : min(z[i - l + 1], r - i + 1);
        while (s[1 + z[i]] == s[i + z[i]])
            z[i]++;
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
    for (int i = 1, l = 0, r = 0; i <= m; i++) {
        p[i] = i > r ? 0 : min(z[i - l + 1], r - i + 1);
        while (p[i] < n && s[1 + p[i]] == t[i + p[i]])
            p[i]++;
        if (i + p[i] - 1 > r)
            l = i, r = i + p[i] - 1;
    }
    long long ans = 0;
    for (int i = 1; i <= n; i++)
        ans ^= 1ll * i * (z[i] + 1);
    cout << ans << endl;
    ans = 0;
    for (int i = 1; i <= m; i++)
        ans ^= 1ll * i * (p[i] + 1);
    cout << ans << endl;
    return 0;
}