#include <bits/stdc++.h>
using namespace std;
int n;
signed main() {
    scanf("%d", &n);
    for (int i = 1; i * i * i <= n; i++) {
        if (i * i * i == n) {
            printf("Yes\n");
            exit(0);
        }
    }
    printf("No\n");
    return 0;
}