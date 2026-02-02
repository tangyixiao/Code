#include <bits/stdc++.h>
using namespace std;
int n, m, k , maxn, id;
signed main() {
    for (int i = 1; i <= 7; i++) {
        scanf("%d %d", &n, &m);
        k = n + m;
        if (k > 8) {
            if (k > maxn) {
                maxn = k;
                id = i;
            }
        }
    }
    printf("%d", id);
    return 0;
}