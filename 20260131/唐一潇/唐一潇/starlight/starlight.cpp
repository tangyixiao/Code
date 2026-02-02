#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 5;
int a[MAXN];
int h[MAXN];
int highbit(int x) {
    return x == 0 ? -1 : 31 - __builtin_clz(x);
}
int main() {
    freopen("starlight.in", "r", stdin);
    freopen("starlight.out", "w", stdout);
    
    int T;
    scanf("%d", &T);
    while (T--) {
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; i++) scanf("%d", &a[i]);
        sort(a, a + n);
        
        for (int i = 0; i < n - 1; i++) 
            h[i] = highbit(a[i] ^ a[i + 1]);
        
        int ans = 0;
        for (int i = 0; i < n - 1; i++) {
            bool ok = true;
            if (i > 0 && h[i] >= h[i - 1]) ok = false;
            if (i < n - 2 && h[i] >= h[i + 1]) ok = false;
            if (ok) ans++;
        }
        printf("%d\n", ans);
    }
    return 0;
}