#include <bits/stdc++.h>
#pragma G++ optimize("O3", "Ofast", "unroll-loops", "inline")
using namespace std;
const int N = 5e5 + 5;
int n, nxt[N], f[N], h[N];
char s[N];
signed main() {
    scanf("%s", s + 1);
    n = strlen(s + 1);
    nxt[0] = -1, f[1] = 1, h[1] = 1;
    for (int i = 2, j = 0; i <= n; ++i) {
        while (j != -1 && s[j + 1] != s[i]) {
            j = nxt[j];
        }
        nxt[i] = ++j;
    }
    for (int i = 2; i <= n; ++i) {
        f[i] = i;
        if (h[f[nxt[i]]] >= i - nxt[i]) {
            f[i] = f[nxt[i]];
        }
        h[f[i]] = i;
    }
    cout << f[n] << endl;
    return 0;
}