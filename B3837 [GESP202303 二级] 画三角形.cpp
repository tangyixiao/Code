#include <bits/stdc++.h>
using namespace std;
int n;
char s = 'A';
signed main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            printf("%c", s);
            s = ((s + 1) - 'A') % 26 + 'A';
        }
        printf("\n");
    }
    return 0;
}