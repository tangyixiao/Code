#include <bits/stdc++.h>
using namespace std;
int n;
void dfs(int x) {
    for (int i = 14; i >= 0; i--) {
        if (x >= pow(2, i)) {
            if (i == 1) {
                printf("2");
            } else if (i == 0) {
                printf("2(0)");
            } else {
                printf("2(");
                dfs(i);
                printf(")");
            }
            x -= pow(2, i);
            if (x) {
                printf("+");
            }
        }
    }
    return;
}
signed main() {
    scanf("%d", &n);
    dfs(n);
    return 0;
}