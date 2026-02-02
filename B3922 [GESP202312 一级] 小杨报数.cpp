
#include <bits/stdc++.h>
using namespace std;
int n, m;
signed main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        if (i % m) {
            printf("%d\n", i);
        }
    }
    return 0;
}