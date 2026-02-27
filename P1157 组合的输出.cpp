#include <bits/stdc++.h>
using namespace std;
int n, r, x[30];
int main() {
    scanf("%d%d", &n, &r);
    for (int i = r + 1; i <= n; ++i)
        x[i] = 1;
    do {
        for (int i = 1; i <= n; ++i)
            if (x[i] == 0)
                printf("%3d", i);
        printf("\n");
    } while (next_permutation(x + 1, x + n + 1));
    return 0;
}
