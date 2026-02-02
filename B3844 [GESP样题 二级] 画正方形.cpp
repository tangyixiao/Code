#include <bits/stdc++.h>
using namespace std;
int n;
signed main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            printf("%c", (i + j - 2) % 26 + 'A');
        }
        printf("\n");
    }
    return 0;
}