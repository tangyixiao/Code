#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5000005;
const int N = 2e7 + 5;

int a[N], b[N];

int main() {
    freopen("tower.in", "r", stdin);
    freopen("tower.out", "w", stdout);

    int T;
    scanf("%d", &T);
    while (T--) {
        int n, m;
        scanf("%d %d", &n, &m);
        int nn = n * 2;
        int k = nn * 2;

        for (int i = 1; i <= nn; i++) {
            scanf("%d", &a[i]);
            a[i + nn] = a[i];
            a[i] -= m;
        }

        int l = nn + 1, r = nn;

        for (int i = 1; i <= n; i++) {
            l--;
            r++;

            if (a[l] + a[r] < 0) {
                l++;
                r++;
            }
        }

        int ans = 0;
        
        for (int i = 1; i <= n; i++) {
            ans = max(ans, a[l] + a[r]);
            l++;
            r--;
        }

        printf("%d\n", ans);
    }

    return 0;
}