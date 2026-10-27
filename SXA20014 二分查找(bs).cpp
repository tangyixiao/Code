#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int n, i, x;
int a[N];

signed main() {
    scanf("%d %d", &n, &x);
    for (i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    for (i = 1; i <= n; i++) {
        if (a[i] == x) {
            printf("%d\n", i);
            return 0;
        }
    }
    printf("Yah that\u2019s a stupid ice elf!\n");
    return 0;
}
